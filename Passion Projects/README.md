## Avionics Flight Computer

Using skills learned from my university courses, I have completed schematic capture in **KiCad** to design hardware that I can test in real-world applications, such as those found in UAVs and rocketry. This project involves end-to-end design tasks, including circuit design, verification, and troubleshooting. I am also applying justifiable design decisions through my choice of COTS components, such as the Raspberry Pi RP2354A.

Using tools such as oscilloscopes to verify and troubleshoot the board's circuitry before integrating onboard instrumentation, such as accelerometers and barometers, was an important aspect of this project. This was particularly important because the project only had one opportunity to launch each year, making it a small-scale introduction to the considerations involved in safety-critical systems found in commercial space launches. These onboard sensors will allow me to collect data during launch for post-flight analysis, while the RRC2+ altimeter system will independently monitor barometric pressure to detect apogee and trigger the drogue deployment system.

In the future, I am planning to use one of the boards as a test article, as I am quite curious about how the system will behave under certain external conditions. For example, heating the board up in an oven to simulate extreme temperatures and investigate how it performs in high-vibration environments by placing it in a metal box and driving around with it secured inside a car (are some ideas). Finding out where and how the board fails is something I am curious about, and I would love to tabulate my findings later this year.

For more context, the computer is intended to be fitted inside the payload tube of a high-power rocket and will therefore be designed to withstand high G-forces. Peak G-force is experienced during the launch off the rail, and during landing, so either could affect the accuracy of the instruments and the reliability of the electronics. Figure 1 shows the schematic of the flight computer through KiCad, and Figure 2-3 shows my board layout that is manufactured.

<p align="center">
  <img src="./Custom Flight Computer/avionicsFlightComputerSchematic.png" alt="Schematic of Avionics Flight Computer" width="80%"> 
<br>
  <i>Figure 1: Schematic of Avionics Flight Computer</i>
</p>

<p align="center">
  <img src="./Custom Flight Computer/avionicsFlightComputerPCBLayout.png" alt="PCB Layout of Flight Computer" width="70%"> 
<br>
  <i>Figure 2: PCB Layout of Avionics Flight Computer</i>
</p>

<p align="center">
  <img src="./Custom Flight Computer/avionicsFlightComputer3DPCB.png" alt="Top view of 3D PCB Layout" width="45%" >
  <img src="./Custom Flight Computer/avionicsFlightComputer3DPCB_bottomview.png" alt="Bottom view of 3D PCB Layout" width="45%"> <br>
  <i>Figure 3: 3D PCB layout of Avionics Flight Computer </i>
</p>

## Solar-Powered Drone

Outside of my courses, I enjoy applying what I learn to real-world applications such as UAVs. This passion project focuses on using theoretical power calculations to design an energy-constrained system. It is something I am super interested in because I have complete control over the project from end to end while solving real engineering design problems.

For now, here is a roadmap of the progress I've made:

* **Performed** the relevant calculations for four 16 × 8 inch propellers and determined the minimum number of solar panels required to power four low-KV brushless DC motors (so the project is feasible).
* **Compiled** a bill of materials (BOM) required for the build.
* **Designed** a proof of concept for the first revision of the solar-powered drone.

The electronics will use COTS components, including an **F405 Flight Controller** and a **60A ESC32** stack. This project pairs well with my avionics flight computer project as I continue learning more about electronics and their UAV applications outside of my coursework. It also gives me the opportunity to integrate the flight computer with the drone in the future.

The reason for using large-diameter propellers and low-KV brushless DC motors is purely for efficiency. Since the system is inherently energy-constrained due to its reliance on solar power, it is important to maximise efficiency wherever possible and justify every design choice against the project's requirements.

## New Zealand Undergraduate Space Challenge
Outside of my courses, I will also be part of a student team developing a satellite designed for launch into space! Working in a multidisciplinary team will naturally bring communication challenges, but I have always seen these as valuable learning opportunities. Separate from the UC Aerospace Club, but under the supervision of engineering faculty such as Phil Gadsby, I am always eager to create new things and tackle challenging engineering problems.

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

Designed and implemented a high-efficiency, closed-loop buck converter to regulate solar panel output for a DC motor in a solar-powered car application. The objective was to maintain operation at the panel’s maximum power point (MPP) while delivering a stable voltage under variable load conditions. The project progressed from initial breadboard testing to veroboard and, finally, to a two-layer PCB designed using KiCad.

Before assembling the design, ensuring that the calculations aligned with the expected simulations in LTspice was an important learning point in this project. Verifying that waveforms matched the expected outputs (e.g. square waveforms) helped confirm that the PWM output was working as intended. This also allowed me to test the design in stages and identify whether the TL494 switching controller, CMOS gate driver, or power stage was failing.

Taking this project end-to-end, from open-loop breadboard testing to transferring the design onto a practical hardware application such as a solar car, took my troubleshooting and design skills to another level. My key learnings from this project are summarised below.

### Key Responsibilities
* **Designed** a DC-DC buck converter from first principles, including inductor sizing, air gap calculation, and capacitor selection
* **Developed** a closed-loop feedback control system using an integrator-based PWM controller
* **Implemented** a MOSFET-based gate driver to improve switching speed and reduce conduction losses
* **Designed and optimized** a custom PCB layout to minimize parasitic inductance, capacitance, and switching noise
* **Characterized** the solar panel to determine maximum power point across varying light conditions
* **Validated performance** through oscilloscope measurements and LTspice simulations

### Key Learnings

* **Developed** my understanding of troubleshooting through oscilloscopes and how specific design decisions can affect how the circuit is behaving
* **Applied power electronics theory** to a real-world renewable energy system
* **Gained practical experience** in magnetic component design (inductor windings, air gap sizing)
* **Strengthened** understanding of switching losses, control stability, and ripple minimisation
* **Developed** PCB layout strategies for high di/dt and dv/dt systems
* **Learned** the importance of iterative testing between simulation and hardware outcomes


In summary, a functional DC-DC buck converter was delivered, being capable of stable voltage regulation under varying solar input and load conditions. Achieved low output voltage ripple and fast switching response (36 ns switching time). Will compete in the Solar Car Competition @ UC on 22nd of Oct!

### Future Improvements

In regards to the project timeline, an asynchronous buck converter was designed for the sake of simplicity. This cut down the time to manufacture, test, and assemble the boards, but obviously leaves room for efficiency gains in the design. 

An avenue I would pursue if continuing the project would be to create a synchronous buck converter, which will need a bootstrap circuit to drive the high-side N-channel MOSFET. This would replace the BS250P PMOS, BS270 NMOS, and SB240S diode in the power stage to a synchronous driver (e.g. a IR21844), along with both IPP034N03L N-channel MOSFETs acting as the low-side and high-side instead. This would effectively allow another MOSFET to be placed in parallel to the free-wheel diode, which when on, would effectively bypass the diode and remove the associated losses in the circuit. 

Due to the limited resources found in the electrical store at the University, only through hole components could be used in the design. Replacing the capacitors and resistors with SMD components would reduce noise by having a smaller di/dt and dv/dt loops while also being able to further reduce the package size.

<p align="center">
  <img src="./Solar Car/breadBoardCMOS.png" alt="Breadboard circuit of a CMOS" width="35%" >
  <img src="./Solar Car/breadBoardCMOS2.png" alt="Breadboard circuit of a CMOS" width="35%"> <br>
  <i>Figure 6: Breadboard circuit of a CMOS Gate Driver</i>
</p>

<p align="center">
  <img src="./Solar Car/breadBoardCMOS.png" alt="Breadboard circuit of a CMOS" width="35%" >
  <img src="./Solar Car/breadBoardCMOS2.png" alt="Breadboard circuit of a CMOS" width="35%"> <br>
  <i>Figure 6: Breadboard circuit of a CMOS Gate Driver</i>
</p>
