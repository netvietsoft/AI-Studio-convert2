# Unknown Surface & Protection Analysis: VSCO

- **Total Native Libraries**: 13
- **Analyzed Symbols**: 240
- **Protection Mechanism**: Rule 11 Clean-Room Preservation

### Stripped Symbols & Obfuscation Audit
Libraries compiled with `-fvisibility=hidden` or stripped via `llvm-strip` have static symbols unlisted in `.dynsym`. These functions remain classified as UNKNOWN to prevent speculative hallucinations.
