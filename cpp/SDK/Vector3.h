#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>

struct Vector3 {
    union {
        struct { float x; float y; float z; };
        float data[3];
    };

    inline Vector3() : x(0), y(0), z(0) {}
    inline Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    static inline Vector3 zero() { return Vector3(0, 0, 0); }
    static inline Vector3 One() { return Vector3(1, 1, 1); }
    static inline Vector3 Right() { return Vector3(1, 0, 0); }
    static inline Vector3 Left() { return Vector3(-1, 0, 0); }
    static inline Vector3 Up() { return Vector3(0, 1, 0); }
    static inline Vector3 Down() { return Vector3(0, -1, 0); }
    static inline Vector3 Forward() { return Vector3(0, 0, 1); }
    static inline Vector3 Backward() { return Vector3(0, 0, -1); }
    
    static inline float Dot(Vector3 lhs, Vector3 rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static inline float Magnitude(Vector3 v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    static inline float SqrMagnitude(Vector3 v) {
        return v.x * v.x + v.y * v.y + v.z * v.z;
    }

    static inline Vector3 Normalized(Vector3 v) {
        float mag = Magnitude(v);
        if (mag == 0) return Vector3::zero();
        return Vector3(v.x / mag, v.y / mag, v.z / mag);
    }

    static inline float Distance(Vector3 a, Vector3 b) {
        return Magnitude(a - b);
    }

    static inline Vector3 Lerp(Vector3 a, Vector3 b, float t) {
        return a + (b - a) * t;
    }

    static inline Vector3 Cross(Vector3 lhs, Vector3 rhs) {
        float x = lhs.y * rhs.z - lhs.z * rhs.y;
        float y = lhs.z * rhs.x - lhs.x * rhs.z;
        float z = lhs.x * rhs.y - lhs.y * rhs.x;
        return Vector3(x, y, z);
    }

    static inline Vector3 Project(Vector3 a, Vector3 b) {
        float m = Magnitude(b);
        if (m == 0) return Vector3::zero();
        return Dot(a, b) / (m * m) * b;
    }

    inline Vector3 operator+(const Vector3 rhs) const { 
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); 
    }
    inline Vector3 operator-(const Vector3 rhs) const { 
        return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); 
    }
    inline Vector3 operator*(const float rhs) const { 
        return Vector3(x * rhs, y * rhs, z * rhs); 
    }
    inline Vector3 operator/(const float rhs) const { 
        return Vector3(x / rhs, y / rhs, z / rhs); 
    }
    inline Vector3& operator+=(const Vector3 rhs) { 
        x += rhs.x; y += rhs.y; z += rhs.z;
        return *this;
    }
    inline Vector3& operator-=(const Vector3 rhs) { 
        x -= rhs.x; y -= rhs.y; z -= rhs.z;
        return *this;
    }
    inline Vector3& operator*=(const float rhs) { 
        x *= rhs; y *= rhs; z *= rhs;
        return *this;
    }
    inline Vector3& operator/=(const float rhs) { 
        x /= rhs; y /= rhs; z /= rhs;
        return *this;
    }
    inline bool operator==(const Vector3 rhs) const { 
        return x == rhs.x && y == rhs.y && z == rhs.z; 
    }
    inline bool operator!=(const Vector3 rhs) const { 
        return !(*this == rhs); 
    }
};

inline Vector3 operator-(Vector3 rhs) {
    return rhs * -1.0f;
}
inline Vector3 operator+(Vector3 lhs, const float rhs) {
    return Vector3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
}
inline Vector3 operator-(Vector3 lhs, const float rhs) {
    return Vector3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
}
inline Vector3 operator*(const float lhs, Vector3 rhs) {
    return Vector3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}
inline Vector3 operator+(const float lhs, Vector3 rhs) {
    return Vector3(rhs.x + lhs, rhs.y + lhs, rhs.z + lhs);
}
