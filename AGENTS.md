# AGENTS.md — instructions for coding agents

## Scope

These instructions apply to the entire repository unless a nested `AGENTS.md` adds stricter module-specific rules.

## Sources of truth

`README.md`, the CMake files, and the C++ source define the current desktop application. The legacy files under `docs/` describe the former web/API proposal and must not be treated as requirements.

## Mandatory architecture

- Native Windows desktop application.
- C++20 + Qt 6 Widgets.
- Text files in `backend/data/` are the runtime input.
- Graph/scheduling core stays in C++ with the Qt UI in `MainWindow`.
- CMake builds the application.

## Autonomy

Small, reversible implementation decisions are allowed. Ask before changing the input-file format, algorithm strategy, or build system.

## Quality

- No over-engineering.
- Stay within task scope.
- Add tests for behavior changes and regression bugs.
- C++: clang-format, clang-tidy, warnings, CTest.
- Never report success if relevant checks fail.

## Secrets

Do not add secrets to the repository.

## Git

Do not commit, push, merge, force-push, or switch branches unless explicitly asked.
