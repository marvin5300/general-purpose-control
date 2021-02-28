#ifndef GPX2_VERSION_H
#define GPX2_VERSION_H

namespace gpx2::CMake::Version {
constexpr int major { @PROJECT_VERSION_MAJOR@ };
constexpr int minor { @PROJECT_VERSION_MINOR@ };
constexpr int patch { @PROJECT_VERSION_PATCH@ };
}

#endif // GPX2_VERSION_H
