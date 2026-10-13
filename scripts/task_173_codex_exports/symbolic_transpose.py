"""Symbolically trace the two literal 16-byte transpose networks at VA 0x659044/0x659220.

This is an aid to manual register-level analysis, not a replacement for Ghidra output.
"""

import json


def trn(a: list[str], b: list[str], lane_bytes: int, odd: bool) -> list[str]:
    a_lanes = [a[i:i + lane_bytes] for i in range(0, 16, lane_bytes)]
    b_lanes = [b[i:i + lane_bytes] for i in range(0, 16, lane_bytes)]
    return [byte for i in range(int(odd), len(a_lanes), 2)
            for lane in (a_lanes[i], b_lanes[i]) for byte in lane]


def main() -> None:
    regs = {name: [f"row{row}_col{column}"
                   for row in (base, base + 8) for column in range(8)]
            for name, base in (("v4", 0), ("v5", 1), ("v6", 2), ("v7", 3),
                               ("v0", 4), ("v1", 5), ("v2", 6), ("v3", 7))}
    network = (
        ("v21", "v4", "v5", 1, False), ("v23", "v4", "v5", 1, True),
        ("v5", "v6", "v7", 1, False), ("v7", "v6", "v7", 1, True),
        ("v4", "v0", "v1", 1, False), ("v1", "v0", "v1", 1, True),
        ("v6", "v2", "v3", 1, False), ("v3", "v2", "v3", 1, True),
        ("v0", "v4", "v6", 2, False), ("v6", "v4", "v6", 2, True),
        ("v2", "v1", "v3", 2, False), ("v3", "v1", "v3", 2, True),
        ("v1", "v23", "v7", 2, False), ("v23", "v23", "v7", 2, True),
        ("v7", "v21", "v5", 2, False), ("v21", "v21", "v5", 2, True),
        ("v4", "v7", "v0", 4, False), ("v0", "v7", "v0", 4, True),
        ("v5", "v1", "v2", 4, False), ("v1", "v1", "v2", 4, True),
        ("v2", "v21", "v6", 4, True), ("v6", "v21", "v6", 4, False),
        ("v7", "v23", "v3", 4, False), ("v3", "v23", "v3", 4, True),
    )
    for destination, left, right, width, odd in network:
        regs[destination] = trn(regs[left], regs[right], width, odd)
    print(json.dumps({name: regs[name] for name in
                      ("v4", "v5", "v6", "v7", "v0", "v1", "v2", "v3")}, indent=2))


if __name__ == "__main__":
    main()
