## ⚠️ _**This is a VR Only Project**_

This is a fan made project of **Superliminal** by **PillowCastle**. This project extends SuperliminalPSX, which was made for 2023 Github Game Jam.

or

**Gamejolt:** https://gamejolt.com/games/SuperliminalPSX/859059

Retro styling and shaders were made by **Daveface**, you can get the retro shader project from here https://github.com/DaveFace/UnrealRetroShaders.

Main tutorial by PastaNoob, you can find his tutorial over here https://www.youtube.com/watch?v=Em8hSFAamYo

## Engine & VR
**Minimum engine version:** Unreal Engine 5.27
All of UE5's features like nanite, lumen and TSR are disabled.

**For Windows:** Use SteamVR or Meta Horizon Link

**For Linux:** Use SteamVR or Wivrn

**_This project has been tested on Meta Quest 2 & 3_**

## Main Components

Most of the core project files are located in the `Content/Superliminal` folder. This directory contains the props, portal, audio assets, and the central Blueprint Interface (`BPI`) that communication across all systems.

<img width="1296" height="464" alt="{98934EAA-8770-47C2-B351-32CA137A843A}" src="https://github.com/user-attachments/assets/85f071a8-3cf2-4f84-8836-d84431c31a4c" />


VR related files are in **VRTemplate**, specifically in the Blueprints folder, there are some other unused template files that unreal includes. I didn't remove them because they break VRPawn for some reason.

<img width="1294" height="457" alt="{303BD8FB-13C7-41B1-88FA-E6B84AA92CB3}" src="https://github.com/user-attachments/assets/8beed433-9d4b-4249-bc98-6ab6bf04af88" />

---

### 👤 VRPawn
The central player character blueprint handling movement controls and the core **forced perspective** (object scaling based on distance) logic. 

Forced perspective logic is written in **C++** for best performance. However a **Blueprint Friendly:** For people who prefer not to touch C++, a fully functional **Blueprint equivalent function** is included within the event graph for easy debugging and modification.

<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/9b4aabda-0534-482a-90b4-1dadb617eed0" />



---

### 📦 BP_Master_Prop
The base parent class for all interactive objects in the game. It handles physics states and player interaction events (grabbing, dropping etc). 

Several  variables are exposed to the **Details Panel** for quick, per-instance level design tweaks:
*   `Is Duplicating Prop` (Boolean): When enabled, attempting to grab the object spawns an exact duplicate near the player.
*   `Is Locked` (Boolean): Disables player interaction entirely and turns off physics simulation.

<img width="1187" height="480" alt="{65FD66B2-049F-4695-B84A-FFBCCFF3E207}" src="https://github.com/user-attachments/assets/2e11c7f9-240f-4963-b2e7-13ca66615168" />

---

### 🎨 BP_Projection
This blueprint handles the optical illusion where a 2D image is projected onto the environment, and can be turned into a physical 3D object when viewed from the correct angle.

*   **Setup:** Drop the blueprint into your level, use the Details Panel to assign the target prop, and select the specific walls/surfaces you want to project the 2D decal onto.
*   **Mechanic:** The blueprint continuously checks the player's camera alignment when they get close. Once the player stands at the exact perspective sweet spot, the projection "releases"—instantly spawning the prop and clearing the 2D projection.
*   **Customization:** You can toggle off the release mechanic in the Details Panel.

<img width="600" height="325" alt="Projection Illusion Comp" src="https://github.com/user-attachments/assets/b9bfc9aa-fbcf-4a02-a52c-81de44c6087d" />

---

### 🌀 BP_PortalNew
**_This is taken from Meta's library as regular desktop portals do not work in VR._**

Manages seamless non-Euclidean portal rendering and player teleportation. Because it inherits directly from `BP_Master_Prop`, portals can be dynamically picked up, carried, and scaled using the player's forced perspective. Portals in VR use a different blueprint compared to regular desktop version.

*   **Setup Guide:**
    1. Place two instances of `BP_PortalNew` into your level.
    2. Use the dropdown picker to link the two portals together. This enables teleportation.
    3. Place two instances of "BP_PortalCaptureActor", one for each portal. In the details panel, assign the **capture portal** (the portal you want to capture) and the **viewing portal** (the portal where you want to display the captured image.
*   ⚠️ **Critical Warning:** Do *not* enable `Is Duplicating Prop` on portal blueprints. Portal replication is not nsupported and may break portal logic.

<img width="800" height="436" alt="image" src="https://github.com/user-attachments/assets/8dd246b7-5c2f-4ee6-a309-a1d6652b5167" />

---
## 📃 Credits
* UE4 Retro Shader by Dave Face
* Retro Meshes by Elbolilloduro
* Arcade Floor Texture from OpenGameArt
* Footsteps & Hit Sounds by Bartosz Kamol Kaminski
* Pop Audio from Mixikit
* Meshes from elbolilloduro on Itch
* Piano by Wufudufu from free3d
* PastaNoob for Superliminal UE5 Guide
* VR Portals by Meta
