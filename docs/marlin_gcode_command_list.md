# Comprehensive Marlin G-code Command List

This document lists the full set of G-code (Gxxx) and M-code (Mxxx) commands supported by Marlin firmware. It is derived from the official Marlin G-code index【236066925561375†L50-L90】 and organized by category. Each command may have additional parameters and variations; refer to the Marlin documentation for details.

## Motion Commands (G-codes)

- **G0, G1** – Linear move: move the toolhead in a straight line【236066925561375†L50-L68】.
- **G2, G3** – Arc or circle move【236066925561375†L50-L70】.
- **G4** – Dwell: pause for a specified time【236066925561375†L50-L70】.
- **G5** – Bézier cubic spline move【236066925561375†L50-L70】.
- **G6** – Direct stepper move【236066925561375†L50-L70】.
- **G10, G11** – Retract and recover (firmware retract / unretract).
- **G12** – Clean the nozzle.
- **G17–G19** – Workspace planes selection.
- **G20** – Set inch units【236066925561375†L60-L67】.
- **G21** – Set millimeter units【236066925561375†L60-L67】.
- **G26** – Mesh validation pattern.
- **G27** – Park toolhead.
- **G28** – Auto home【236066925561375†L64-L65】.
- **G29** – Bed leveling (multiple subcommands for different leveling methods)【236066925561375†L65-L70】.
- **G30** – Single Z-probe.
- **G31, G32** – Dock and undock sled.
- **G34** – Auto calibration.
- **G38.2–G38.5** – Probe target.

…and more. Marlin defines additional G-codes such as G80 (cancel motion mode), G90 (absolute positioning), G91 (relative positioning), G92 (set position)【236066925561375†L86-L90】, and extended codes like G425 for backlash calibration【236066925561375†L86-L90】.

## M-code Categories

### Control of Motors and Fans

- **M17** – Enable steppers【236066925561375†L89-L99】.
- **M18 / M84** – Disable steppers【236066925561375†L90-L99】.
- **M80** – Power on【236066925561375†L123-L124】.
- **M81** – Power off【236066925561375†L124-L125】.
- **M106** – Set fan speed【236066925561375†L135-L136】.
- **M107** – Fan off【236066925561375†L136-L137】.

### Temperature and Extrusion

- **M104** – Set hotend temperature【236066925561375†L133-L135】.
- **M105** – Report temperatures【236066925561375†L133-L135】.
- **M109** – Wait for hotend temperature【236066925561375†L137-L138】.
- **M140** – Set bed temperature.
- **M190** – Wait for bed temperature【236066925561375†L168-L170】.
- **M82 / M83** – Absolute / relative extrusion【236066925561375†L123-L127】.
- **M92** – Set axis steps per unit【236066925561375†L129-L131】.

### SD Card and File Operations

- **M20** – List SD card files【236066925561375†L90-L100】.
- **M21** – Initialize SD card【236066925561375†L90-L103】.
- **M22** – Release SD card.
- **M23** – Select SD file【236066925561375†L103-L104】.
- **M24** – Start / resume SD print【236066925561375†L104-L105】.
- **M25** – Pause SD print【236066925561375†L104-L105】.
- **M26** – Set SD file position【236066925561375†L105-L106】.
- **M27** – Report SD print status【236066925561375†L106-L107】.
- **M28** – Begin SD write【236066925561375†L107-L108】.
- **M29** – End SD write【236066925561375†L108-L109】.
- **M30** – Delete SD file【236066925561375†L109-L110】.
- **M31** – Report print time【236066925561375†L110-L111】.
- **M32** – Select and start a file【236066925561375†L111-L112】.
- **M33** – Get long file path【236066925561375†L112-L113】.

### Advanced Motion and Calibration

- **M203** – Set max feedrate【236066925561375†L174-L176】.
- **M204** – Set starting acceleration【236066925561375†L176-L178】.
- **M205** – Set advanced settings【236066925561375†L176-L178】.
- **M206** – Set home offsets【236066925561375†L178-L179】.
- **M207–M208** – Firmware retraction settings / recovery【236066925561375†L178-L182】.
- **M211** – Software endstops【236066925561375†L183-L184】.
- **M350** – Set micro-stepping【236066925561375†L206-L208】.
- **M351** – Set microstep pins【236066925561375†L206-L208】.
- **M400** – Finish moves【236066925561375†L216-L217】.
- **M401, M402** – Deploy and stow probe【236066925561375†L216-L218】.
- **M420** – Report bed leveling state【236066925561375†L224-L228】.
- **M500–M503** – Save, restore, or report settings【236066925561375†L236-L239】.
- **M600** – Filament change【236066925561375†L243-L244】.
- **M605** – Multi nozzle mode【236066925561375†L253-L255】.
- **M665, M666** – Delta / dual endstop adjustments【236066925561375†L254-L258】.
- **M851** – Probe offset【236066925561375†L260-L266】.
- **M900** – Linear advance factor【236066925561375†L270-L271】.

### Miscellaneous and Misc

Marlin defines many additional commands for calibration, sensors, timers, display control, TMC driver configuration, etc. Consult the official index for the complete list【236066925561375†L160-L289】.

---

This document serves as a reference for the commands that CNCSharp will support through its Marlin backend. Each command will be mapped to an appropriate high-level operation in the CNCSharp DSL and converted to Marlin G-code using the backend's generator.
