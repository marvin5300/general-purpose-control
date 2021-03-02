#ifndef GENERAL_PURPOSE_CONTROL_VERSION_H
#define GENERAL_PURPOSE_CONTROL_VERSION_H

namespace CMake::Version {
constexpr int major { @PROJECT_VERSION_MAJOR@ };
constexpr int minor { @PROJECT_VERSION_MINOR@ };
constexpr int patch { @PROJECT_VERSION_PATCH@ };
}

#endif // GENERAL_PURPOSE_CONTROL_VERSION_H
