#include <iostream>
#include <cmath>

#define PI 3.14159265f

// Yardimci fonksiyonlar
float smooth(float t) { return t * t * (3.0f - 2.0f * t); }
float lerp_f(float a, float b, float t) { return a + (b - a) * t; }

// ================================================================
// WALK
// ================================================================
float hip_r_walk(float t) { return 14.0f * sinf(2 * PI * t + 90.0f * PI / 180.0f); }
float hip_l_walk(float t) { return 14.0f * sinf(2 * PI * t + 270.0f * PI / 180.0f); }
float knee_r_walk(float t) {
    float hip = sinf(2 * PI * t + 90.0f * PI / 180.0f);
    float raw = sinf(2 * PI * t + 90.0f * PI / 180.0f - 60.0f * PI / 180.0f);
    return hip >= 0.0f ? fmaxf(0.0f, raw) * 34.0f : fmaxf(0.0f, raw) * 15.0f;
}
float knee_l_walk(float t) {
    float hip = sinf(2 * PI * t + 270.0f * PI / 180.0f);
    float raw = sinf(2 * PI * t + 270.0f * PI / 180.0f - 60.0f * PI / 180.0f);
    return hip >= 0.0f ? fmaxf(0.0f, raw) * 34.0f : fmaxf(0.0f, raw) * 15.0f;
}
float ankle_r_walk(float t) {
    float air = fmaxf(0.0f, sinf(2 * PI * t + 90.0f * PI / 180.0f));
    return 20.0f * air + 10.0f * (1.0f - air);
}
float ankle_l_walk(float t) {
    float air = fmaxf(0.0f, sinf(2 * PI * t + 270.0f * PI / 180.0f));
    return 20.0f * air + 10.0f * (1.0f - air);
}
float shoulder_r_walk(float t) { return -20.0f * sinf(2 * PI * t + 90.0f * PI / 180.0f); }
float shoulder_l_walk(float t) { return -20.0f * sinf(2 * PI * t + 270.0f * PI / 180.0f); }
float elbow_r_walk(float t) { return 15.0f + 10.0f * fmaxf(0.0f, sinf(2 * PI * t)); }
float elbow_l_walk(float t) { return 15.0f + 10.0f * fmaxf(0.0f, sinf(2 * PI * t + PI)); }
float body_y_walk(float t) { return 0.0f; }

// ================================================================
// RUN
// ================================================================
float hip_r_run(float t) { return 35.0f * sinf(2 * PI * t + 90.0f * PI / 180.0f); }
float hip_l_run(float t) { return 35.0f * sinf(2 * PI * t + 270.0f * PI / 180.0f); }
float knee_r_run(float t) {
    float hip = sinf(2 * PI * t + 90.0f * PI / 180.0f);
    float raw = sinf(2 * PI * t + 90.0f * PI / 180.0f - 60.0f * PI / 180.0f);
    return hip >= 0.0f ? fmaxf(0.0f, raw) * 65.0f : fmaxf(0.0f, raw) * 25.0f;
}
float knee_l_run(float t) {
    float hip = sinf(2 * PI * t + 270.0f * PI / 180.0f);
    float raw = sinf(2 * PI * t + 270.0f * PI / 180.0f - 60.0f * PI / 180.0f);
    return hip >= 0.0f ? fmaxf(0.0f, raw) * 65.0f : fmaxf(0.0f, raw) * 25.0f;
}
float ankle_r_run(float t) {
    float air = fmaxf(0.0f, sinf(2 * PI * t + 90.0f * PI / 180.0f));
    return 25.0f * air + 10.0f * (1.0f - air);
}
float ankle_l_run(float t) {
    float air = fmaxf(0.0f, sinf(2 * PI * t + 270.0f * PI / 180.0f));
    return 25.0f * air + 10.0f * (1.0f - air);
}
float shoulder_r_run(float t) { return -40.0f * sinf(2 * PI * t + 90.0f * PI / 180.0f); }
float shoulder_l_run(float t) { return -40.0f * sinf(2 * PI * t + 270.0f * PI / 180.0f); }
float elbow_r_run(float t) { return 60.0f + 15.0f * fmaxf(0.0f, sinf(2 * PI * t)); }
float elbow_l_run(float t) { return 60.0f + 15.0f * fmaxf(0.0f, sinf(2 * PI * t + PI)); }
float body_y_run(float t) { return -8.0f * fabsf(sinf(4 * PI * t)); }

// ================================================================
// JUMP (simetrik)
// ================================================================
float hip_jump(float t) {
    if (t < 0.3f) return -lerp_f(0, 45.0f, smooth(t / 0.3f));
    if (t < 0.5f) return -lerp_f(45.0f, 0, smooth((t - 0.3f) / 0.2f));
    return 0.0f;
}
float knee_jump(float t) {
    if (t < 0.3f)  return lerp_f(0, 85.0f, smooth(t / 0.3f));
    if (t < 0.5f)  return lerp_f(85.0f, 0, smooth((t - 0.3f) / 0.2f));
    if (t < 0.7f)  return lerp_f(0, 10.0f, smooth((t - 0.5f) / 0.2f));
    if (t < 0.82f) return lerp_f(10.0f, 20.0f, smooth((t - 0.7f) / 0.12f));
    return lerp_f(20.0f, 0, smooth((t - 0.82f) / 0.18f));
}
float ankle_jump(float t) {
    if (t < 0.3f)  return lerp_f(0, 12.0f, smooth(t / 0.3f));
    if (t < 0.5f)  return lerp_f(12.0f, 0, smooth((t - 0.3f) / 0.2f));
    if (t < 0.7f)  return lerp_f(0, 15.0f, smooth((t - 0.5f) / 0.2f));
    if (t < 0.78f) return lerp_f(15.0f, 0, smooth((t - 0.7f) / 0.08f));
    return 0.0f;
}
float shoulder_jump(float t) {
    if (t < 0.3f) return lerp_f(0, -19.5f, smooth(t / 0.3f));
    if (t < 0.5f) return lerp_f(-19.5f, -65.0f, smooth((t - 0.3f) / 0.2f));
    if (t < 0.7f) return lerp_f(-65.0f, -26.0f, smooth((t - 0.5f) / 0.2f));
    return lerp_f(-26.0f, 0, smooth((t - 0.7f) / 0.3f));
}
float elbow_jump(float t) {
    if (t < 0.5f) return lerp_f(20.0f, 75.0f, smooth(t / 0.5f));
    return lerp_f(75.0f, 20.0f, smooth((t - 0.5f) / 0.5f));
}
float body_y_jump(float t) {
    if (t < 0.3f)  return lerp_f(0, 12.0f, smooth(t / 0.3f));
    if (t < 0.5f)  return lerp_f(12.0f, -90.0f, smooth((t - 0.3f) / 0.2f));
    if (t < 0.7f)  return lerp_f(-90.0f, 0, smooth((t - 0.5f) / 0.2f));
    if (t < 0.82f) return lerp_f(0, 8.0f, smooth((t - 0.7f) / 0.12f));
    return lerp_f(8.0f, 0, smooth((t - 0.82f) / 0.18f));
}

// ================================================================
// KICK
// ================================================================
float hip_r_kick(float t) {
    if (t < 0.3f) return lerp_f(0, -20.0f, smooth(t / 0.3f));
    if (t < 0.5f) return -20.0f;
    if (t < 0.7f) return lerp_f(-20.0f, -60.0f, smooth((t - 0.5f) / 0.2f));
    return lerp_f(-60.0f, 0, smooth((t - 0.7f) / 0.3f));
}
float knee_r_kick(float t) {
    if (t < 0.3f) return 0.0f;
    if (t < 0.5f) return lerp_f(0, 80.0f, smooth((t - 0.3f) / 0.2f));
    if (t < 0.7f) return lerp_f(80.0f, 0, smooth((t - 0.5f) / 0.2f));
    return 0.0f;
}
float ankle_r_kick(float t) {
    if (t < 0.5f) return 0.0f;
    if (t < 0.7f) return lerp_f(0, 15.0f, smooth((t - 0.5f) / 0.2f));
    return lerp_f(15.0f, 0, smooth((t - 0.7f) / 0.3f));
}
float hip_l_kick(float t) { return 0.0f; }
float knee_l_kick(float t) { return 10.0f; }
float ankle_l_kick(float t) { return 0.0f; }
float shoulder_r_kick(float t) {
    if (t < 0.5f) return lerp_f(0, 25.0f, smooth(t / 0.5f));
    return lerp_f(25.0f, 0, smooth((t - 0.5f) / 0.5f));
}
float shoulder_l_kick(float t) {
    if (t < 0.5f) return lerp_f(0, -30.0f, smooth(t / 0.5f));
    return lerp_f(-30.0f, 0, smooth((t - 0.5f) / 0.5f));
}
float elbow_r_kick(float t) { return 60.0f; }
float elbow_l_kick(float t) { return 60.0f; }
float body_y_kick(float t) { return 0.0f; }

// ================================================================
// TEST
// ================================================================
void print_motion(const char* name,
    float(*hip_r)(float), float(*hip_l)(float),
    float(*knee_r)(float), float(*knee_l)(float),
    float(*ankle_r)(float), float(*ankle_l)(float),
    float(*shoulder_r)(float), float(*shoulder_l)(float),
    float(*elbow_r)(float), float(*elbow_l)(float),
    float(*body_y)(float))
{
    std::cout << "\n=== " << name << " ===" << std::endl;
    std::cout << "t\tHip_R\tHip_L\tKnee_R\tKnee_L\tAnkle_R\tShoulder_R\tElbow_R\tBodyY" << std::endl;
    for (int i = 0; i <= 10; i++) {
        float t = i / 10.0f;
        std::cout << t
            << "\t" << hip_r(t)
            << "\t" << hip_l(t)
            << "\t" << knee_r(t)
            << "\t" << knee_l(t)
            << "\t" << ankle_r(t)
            << "\t" << shoulder_r(t)
            << "\t\t" << elbow_r(t)
            << "\t" << body_y(t)
            << std::endl;
    }
}

int main() {
    print_motion("WALK",
        hip_r_walk, hip_l_walk,
        knee_r_walk, knee_l_walk,
        ankle_r_walk, ankle_l_walk,
        shoulder_r_walk, shoulder_l_walk,
        elbow_r_walk, elbow_l_walk,
        body_y_walk);

    print_motion("RUN",
        hip_r_run, hip_l_run,
        knee_r_run, knee_l_run,
        ankle_r_run, ankle_l_run,
        shoulder_r_run, shoulder_l_run,
        elbow_r_run, elbow_l_run,
        body_y_run);

    print_motion("JUMP",
        hip_jump, hip_jump,
        knee_jump, knee_jump,
        ankle_jump, ankle_jump,
        shoulder_jump, shoulder_jump,
        elbow_jump, elbow_jump,
        body_y_jump);

    print_motion("KICK",
        hip_r_kick, hip_l_kick,
        knee_r_kick, knee_l_kick,
        ankle_r_kick, ankle_l_kick,
        shoulder_r_kick, shoulder_l_kick,
        elbow_r_kick, elbow_l_kick,
        body_y_kick);

    return 0;
}