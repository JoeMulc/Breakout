# Breakout

W Kavanagh. June Summer 2024

## controls

A/D to move the paddle right and left.
P to pause.

## Powerups

big/small paddle (blue)
fast/slow ball (fancy yellow)
fire ball (green)

# Tasklist

## Suggested fixes

* Fix the compiler issues in the code

## Suggested tasks

* Implement mouse input for pad
* Improved VFX (ball trail, paddle hit response, brick particle destruction)
* Better UI (progress bar rather than timer for countdown).
* GameLoop
* Better ball physics (Box2D)
* Leaderboards
* More ball types (e.g., multiball, sticky ball [where you shoot the ball from the paddle every time], tiny ball, big ball, brick-tracking ball)
* Sounds with increasing tone between bounces.
* Implement commentary with calls to an LLM such as LLama

# Time Details and Changelist
<Add information to this section about the time you've taken for this task along with a professional changelist.>

21/10/2024
21:19 Fixed circular dependancy i think.

22/10/20204
17:08 Implemented simple mouse input where paddle moves right if mouse is on right segment of screen and vice versa
17:11 Implemented improved mouse input where paddle moves towards mouse depending on its location compared to itself.
17:39 Working on screen shake still
17:45 Screen flips when hit, starting on real screen shake now. 
17:56 bug found in mouse movement.
18:05 Mouse bug fixed where mouse was affecting movement when not intended. Mouse movement still could be refined but moving back to screen shake.
18:20 basic screen shake added
18:30 screenshake function completed
18:53 bug fixes - forward declaration in ball cpp and initial view fixed
19:00 screenshake added to more ball collisions
19:02 looking over powerup implementation, plan to add more powerups
