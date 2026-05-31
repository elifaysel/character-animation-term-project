# Character Animation — Term Project
**Student:** Elif Aysel Yıldırım  - 220201046
**Course:** Character Animation: Modeling, Simulation and Human Motion Control
**Deadline:** May 31, 2026
Link: https://drive.google.com/file/d/1yasithkyvp7-8qHunjQX8uwv9NoXSipE/view?usp=sharing

## Motion States Implemented
- Walk
- Run  
- Jump
- Kick

## Joints Controlled (10 joints)
- Left & Right Hip
- Left & Right Knee
- Left & Right Ankle
- Left & Right Shoulder
- Left & Right Elbow

## Files
- `CharacterAnimation.cpp` — C++ kinematic joint angle model (DLL for N8RO)
- `character_animation.html` — Web-based animation visualizer
- `ai_assistance.md` — AI usage log

## How It Works
Kinematic joint angle model computing 10 joint angles per frame.
Each motion uses sinusoidal functions (Walk, Run) or phase-based
interpolation (Jump, Kick). Integrated as a DLL plugin into N8RO.

## N8RO Integration
The DLL integration into N8RO successfully loads and applies Walk motion
via the joint angle model. Run, Jump, and Kick motions are fully implemented
in the C++ code but could not be triggered through the N8RO interface due to
platform limitations encountered during development.

## Web Visualizer
A web-based visualizer (character_animation.html) was created to demonstrate
all 4 motion states with real-time joint angle visualization. Open the HTML
file in any browser to see Walk, Run, Jump, and Kick animations with all
10 joint values displayed.
