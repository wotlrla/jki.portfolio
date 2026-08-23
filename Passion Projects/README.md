## Avionics Flight Computer

Using skills learned from my university courses, I have created a schematic using **KiCad** that I will test in real-world applications such as those found in UAVs and rocketry. This project involves design tasks such as schematic circuit design, verification, and characterisation, using COTS components such as the Raspberry Pi RP2354A. It also involves testing and validating hardware using tools such as oscilloscopes, as well as working with instrumentation such as accelerometers and barometers.

So far, I have completed my schematic and PCB layout during my free time. In the future I will be assembling, testing, and validating the project for use in aerospace applications! The computer is intended to be fitted inside the payload tube of a high-power rocket and will therefore be designed to withstand large G-forces that could affect the accuracy of the instruments and electronics.

<p align="center">
  <img src="./Flight Computer/avionicsFlightComputerSchematic.png" alt="Schematic of Avionics Flight Computer" width="80%"> 
<br>
  <i>Figure 1: Schematic of Avionics Flight Computer</i>
</p>

<p align="center">
  <img src="./Flight Computer/avionicsFlightComputerPCBLayout.png" alt="PCB Layout of Flight Computer" width="70%"> 
<br>
  <i>Figure 2: PCB Layout of Avionics Flight Computer</i>
</p>

<p align="center">
  <img src="./Flight Computer/avionicsFlightComputer3DPCB.png" alt="Top view of 3D PCB Layout" width="45%" >
  <img src="./Flight Computer/avionicsFlightComputer3DPCB_bottomview.png" alt="Bottom view of 3D PCB Layout" width="45%"> <br>
  <i>Figure 3: 3D PCB layout of Avionics Flight Computer </i>
</p>

## Solar-Powered Drone

Outside of my courses, I enjoy applying what I learn to real-world applications such as UAVs. This passion project focuses on using theoretical power calculations to design an energy-constrained system. It is something I am super interested in because I have complete control over the project from end to end while solving real engineering design problems.

For now, here is a roadmap of the progress I've made:

* **Performed** the relevant calculations for four 16 × 8 inch propellers and determined the minimum number of solar panels required to power four low-KV brushless DC motors (so the project is feasible).
* **Compiled** a bill of materials (BOM) required for the build.
* **Designed** a proof of concept for the first revision of the solar-powered drone.

The electronics will use COTS components, including an **F405 Flight Controller** and a **60A ESC32** stack. This project pairs well with my avionics flight computer project as I continue learning more about electronics and their UAV applications outside of my coursework. It also gives me the opportunity to integrate the flight computer with the drone in the future.

The reason for using large-diameter propellers and low-KV motors is purely for efficiency. Since the system is inherently energy-constrained due to its reliance on solar power, it is important to maximise efficiency wherever possible and justify every design choice against the project's requirements.

## New Zealand Undergraduate Space Challenge
Outside of my courses, I will also be part of a student team developing a satellite designed for launch into space! Working in a multidisciplinary team will naturally bring communication challenges, but I have always seen these as valuable learning opportunities. Separate from the UC Aerospace Club, but under the supervision of engineering faculty such as Phil Gadsby, I am always eager to create new things and tackle challenging engineering problems!

I will be applying skills learned at university, such as **CAD Modelling** and **KiCad**, to develop payload experiments that will be integrated into a shared CubeSat platform. Gaining hands-on experience in aerospace applications like this will continue to develop my skills as an engineering student, and I hope to make a meaningful impact in whichever industry I pursue.

<p align="center">
  <img src="./NZUSC.png" alt="NZUSC Challenge" width="65%"> <br>
  <i>Figure 4: NZUSC Challenge</i>
</p>

## Audio Amplifier
An introduction to power electronics inspired me to create a circuit that can be used in conjunction with audio devices. Using concepts such as a non-inverting amplifier, I created the foundation of a Class AB gain stage.

Real-world applications use the same concepts of AC/DC power conversion, where devices such as a Static Synchronous Compensator (STATCOM) improve power quality in electrical power systems. Starting with smaller projects like this to build upon what I learn in my courses is something I am very passionate about.

A roadmap of what I would love to build on includes:

* **Optimising** the bias of the FETs so that the input signals do not saturate or clip.
* **Designing** a buffer stage to ensure I have a strong voltage signal before applying current gain in the output stage (a pre-amplifier).
* **Developing** both input filtering (using a choke) and output filtering to remove unwanted harmonics.

<p align="center">
  <img src="./Audio Amplifier/audioAmplifierSchematic.png" alt="Schematic of Audio Amplifier" width="45%" >
  <img src="./Audio Amplifier/topViewPCB.png" alt="3D PCB layout" width="45%"> <br>
  <i>Figure 5: Schematic and 3D PCB layout of Audio Amplifier </i>
</p>

## Solar Car
With a broader understanding of power electronics under my belt, I wanted to explore a purely analogue design using a **PMOS/NMOS Synchronous Buck Converter** as a step-down DC-DC power conversion stage. Since the solar car relies on photovoltaic power from the sun, the PCB layout must be as efficient as possible. Minimising trace lengths and ensuring optimal signal feedback are key design considerations for this project. Using **LTspice simulation**, I can check whether my calculations match expected values.

Further improvements to the design could be explored by replacing the high-side PMOS with an NMOS and adding a bootstrap gate-drive circuit. This would create a **Dual-NMOS Synchronous Buck Converter**, potentially reducing conduction losses and improving the overall efficiency of the converter. Maximising efficiency in this way allows more of the available solar power to be delivered to the motor drivers while reducing power lost as heat. 

Ensuring that the solar panels operate within their rated 16–17.5 V range for maximum power output to the motor drivers is an engineering design challenge that requires careful PCB layout and power system design. I will be working collaboratively on this project with two others, so stay tuned for updates throughout the year!

<p align="center">
  <img src="./Solar Car/breadBoardCMOS.png" alt="Breadboard circuit of a CMOS" width="35%" >
  <img src="./Solar Car/breadBoardCMOS2.png" alt="Breadboard circuit of a CMOS" width="35%"> <br>
  <i>Figure 6: Breadboard circuit of a CMOS Gate Driver</i>
</p>
