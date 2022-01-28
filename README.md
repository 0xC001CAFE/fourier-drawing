# Fourier Drawing

## Projekt ausführen

Bevor das Projekt ausgeführt werden kann, muss die PATH-Umgebungsvariable erweitert werden.

1. Projekt mit Visual Studio öffnen
2. Projekteigenschaften abrufen (unter "Projekt" - "Eigenschaften")
3. Unter "Debugging" ist die Eigenschaft "Umgebung" zu finden
4. Pfad `PATH=%PATH%;$(ProjectDir)..\SDL2\lib\x64` zur Eigenschaft "Umgebung" hinzufügen
   ![](/setup_environment.png)
5. Projekt kann nun übersetzt und ausgeführt werden
