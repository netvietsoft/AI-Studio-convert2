# Evidence handling

Worker log is the complete fetched GitHub job text with ANSI controls removed and authentication URLs redacted. Its SHA-256 identifies this sanitized artifact, not the untouched remote log. The dispatcher file is a selected, verbatim line excerpt after the same sanitization. Re-fetch source logs using job IDs 112067979241 and 112067630364.

GitHub job labels [self-hosted] are requested scheduling labels; they do not enumerate all registered labels of runner 25. API timestamps differ from wall-clock timestamps embedded in logs; retain both without asserting clock alignment. Interactive shell tool resolution is not runner-service environment proof. Mock AGY fixtures validate failure handling and cannot establish TASK_060 PASS or TASK_059 execution.

