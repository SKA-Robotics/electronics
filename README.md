# Electronics
This repository contains documentation of electronic modules used on Sirius 2 Rover.

## How to use this repository
First, clone this repository to your computer.

```bash
$ git clone https://github.com/SKA-Robotics/electronics
```
Open ``SKAR.DsnWrk`` file in Altium designer.
This will load every project into your workspace, allowing you to browse or edit any of them.
When adding a new project, make sure it's part of the project group.

## Maintaining clean and readable documentation

To ensure that everyone can read the documentation, include following files in the final release:
- Datasheets of all important components used
- Any custom libraries containing schematic and layout files
- Schematic **in *.PDF* format**
- Manufacturing data (X2 gerbers)
- Exported 3D model in *.step* format (make sure your stackup has correct thickness set!)
- Images or 3D renders of the both sides
- A short README with description of your board, functionalities, connectors and instructions

