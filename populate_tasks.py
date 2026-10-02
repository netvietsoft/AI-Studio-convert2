import json
import os

tasks = [
    {
        "folder": ".ai/tasks/running",
        "task": {
            "task_id": "HCE-C0-CONTRACT",
            "title": "Shared Contract Freeze (HCE_CONTRACT_V1)",
            "phase": "HCE-C0",
            "status": "RUNNING",
            "assigned_agent": "Agent_1",
            "dependencies": {
                "start": ["P0_FINAL_PASS_RECONFIRMED"],
                "contract": [],
                "merge": [],
                "acceptance": ["Architecture Audit"]
            },
            "output_artifacts": [
                "Docs/Architecture/HairEngine/HCE_CONTRACT_V1.md",
                "Docs/Architecture/HairEngine/HCE_DOWNSTREAM_CODE_AUDIT.md",
                "lib-core-graphics/src/main/cpp/include/hair_engine_contracts.h"
            ]
        }
    },
    {
        "folder": ".ai/tasks/ready",
        "task": {
            "task_id": "HCE-P1-ARCH",
            "title": "Hair Orientation & Flow Field Architecture",
            "phase": "P1",
            "status": "READY",
            "assigned_agent": "Agent_P1",
            "dependencies": {
                "start": ["HCE-C0-CONTRACT"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["P1 Architecture Review"]
            }
        }
    },
    {
        "folder": ".ai/tasks/ready",
        "task": {
            "task_id": "HCE-P2-ARCH",
            "title": "Flow-Aware Hair Texture Architecture",
            "phase": "P2",
            "status": "READY",
            "assigned_agent": "Agent_P2",
            "dependencies": {
                "start": ["HCE-C0-CONTRACT"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["P2 Architecture Review"]
            }
        }
    },
    {
        "folder": ".ai/tasks/ready",
        "task": {
            "task_id": "HCE-P3-ARCH",
            "title": "Appearance / Shadow / Highlight Architecture",
            "phase": "P3",
            "status": "READY",
            "assigned_agent": "Agent_P3",
            "dependencies": {
                "start": ["HCE-C0-CONTRACT"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["P3 Architecture Review"]
            }
        }
    },
    {
        "folder": ".ai/tasks/ready",
        "task": {
            "task_id": "HCE-P4-ARCH",
            "title": "Hair Dye Material / Color Response Architecture",
            "phase": "P4",
            "status": "READY",
            "assigned_agent": "Agent_P4",
            "dependencies": {
                "start": ["HCE-C0-CONTRACT"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["P4 Architecture Review"]
            }
        }
    },
    {
        "folder": ".ai/tasks/ready",
        "task": {
            "task_id": "HCE-P5-ARCH",
            "title": "Anisotropic Specular Architecture",
            "phase": "P5",
            "status": "READY",
            "assigned_agent": "Agent_P5",
            "dependencies": {
                "start": ["HCE-C0-CONTRACT"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["P5 Architecture Review"]
            }
        }
    },
    {
        "folder": ".ai/tasks/ready",
        "task": {
            "task_id": "HCE-P6-ARCH",
            "title": "GPU Production Backend Architecture (Vulkan/Metal)",
            "phase": "P6",
            "status": "READY",
            "assigned_agent": "Agent_P6",
            "dependencies": {
                "start": ["HCE-C0-CONTRACT"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["P6 Architecture Review"]
            }
        }
    },
    {
        "folder": ".ai/tasks/backlog",
        "task": {
            "task_id": "HCE-INTEGRATION",
            "title": "Cross-Phase Pipeline Integration Assembly",
            "phase": "INTEGRATION",
            "status": "BACKLOG",
            "assigned_agent": "Agent_Integ",
            "dependencies": {
                "start": ["HCE-P1-IMPL", "HCE-P2-IMPL", "HCE-P3-IMPL", "HCE-P4-IMPL", "HCE-P5-IMPL", "HCE-P6-IMPL"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": ["All Implementation Worktrees"],
                "acceptance": ["Unified Integration Pass"]
            }
        }
    },
    {
        "folder": ".ai/tasks/backlog",
        "task": {
            "task_id": "HCE-E2E-TEST",
            "title": "End-to-End Regression & Parity Testing",
            "phase": "TEST",
            "status": "BACKLOG",
            "assigned_agent": "Agent_Tester",
            "dependencies": {
                "start": ["HCE-INTEGRATION"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["62 Ground Truth Samples 100% Pass"]
            }
        }
    },
    {
        "folder": ".ai/tasks/backlog",
        "task": {
            "task_id": "HCE-FINAL-FREEZE",
            "title": "Master Cryptographic Freeze & Final Report",
            "phase": "FREEZE",
            "status": "BACKLOG",
            "assigned_agent": "Agent_0",
            "dependencies": {
                "start": ["HCE-E2E-TEST", "HCE-VISUAL-REVIEW"],
                "contract": ["HCE_CONTRACT_V1"],
                "merge": [],
                "acceptance": ["Independent Reviewer Approval"]
            }
        }
    }
]

for item in tasks:
    os.makedirs(item["folder"], exist_ok=True)
    file_path = os.path.join(item["folder"], f"{item['task']['task_id']}.json")
    with open(file_path, "w", encoding="utf-8") as f:
        json.dump(item["task"], f, indent=2, ensure_ascii=False)
    print(f"Created {file_path}")
