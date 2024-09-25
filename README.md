<div align="center">
<h1>malicious-binary</h1>
</div>

<p align="center">
    <a href="#introduction">Introduction</a> •
    <a href="#file-structure">File Structure</a> •
    <a href="#usage">Usage</a> •
    <a href="#disclaimer">Disclaimer</a>
</p>

## Introduction
**malicious-binary** is a repository for malware development practice, malware analysis and threat prevention. Most of the malwares here will be harmless (e.g. copying/creating/reading files on the victim's system). 

The aim of this repository is mostly for personal practice but you're free to use this as a starting point for educational and research purposes.

> [!WARNING]
> Although many files here can be technically harmless, it is still advised to only run these malwares in a controlled environment for testing and analysing purposes. **_DO NOT USE THESE MALWARES ON YOUR HOST DEVICE OR A DEVICE YOU DON'T EXPLICITLY CONTROL._**


## File Structure
The source code for different malwares are located inside the **_type_** of malware they most closely resemble. 

For example, the file `hermes_sandals.c` is located inside the `trojans` directory as the purpose of this malware is to masquerade as a legitimate program (simple note taking mechanism) while performing malicious tasks in the background without the users' permission (copying the contents of `/etc/passwd`). The compatible DISTRO for specific binaries are listed in the source code itself.

### Example file structure:

- malicious-binary
    - trojans
        - hermes_sandals.c

It is possible that some malwares don't strictly fit into any one category. In this case, the source code will be located inside the primary and most malicious function of the malware.


## Usage
Clone the repository :
```
git clone https://github.com/sapphicart/malicious-binary.git
```
Alternatively, head over to [releases](https://github.com/sapphicart/malicious-binary/releases) and download the source code to perform modifications or compile the binary yourself.

The steps/tips for preventing against the particular malware attack will be listed inside the source code.


## Disclaimer
> [!IMPORTANT]
> **This software is provided for educational and research purposes only.**

It is not intended for any illegal activities or unauthorized use. By using this software, you agree to comply with all applicable laws, regulations, and ethical guidelines.

The developer(s) and contributor(s) of this software are not responsible for any misuse, damages, or illegal activities conducted with this software. The software is provided "as is," without any warranties or guarantees of any kind, including but not limited to merchantability or fitness for a particular purpose.

Users are advised to use this software responsibly and with the explicit consent of system owners. Unauthorized use of this software on systems without proper authorization is strictly prohibited.

The software should be used only on systems owned or controlled by the user or with explicit permission from the system owner. Any unauthorized use of this software may violate local, national, and international laws and regulations.

The developer(s) and contributor(s) of this software shall not be held liable for any direct, indirect, incidental, special, exemplary, or consequential damages arising out of the use or inability to use this software, including but not limited to procurement of substitute goods or services, loss of use, data, or profits, or business interruption, even if advised of the possibility of such damages.

Users are solely responsible for their use of this software and should exercise caution, discretion, and ethical considerations when using it. It is the user's responsibility to ensure compliance with all applicable laws and regulations.

By using this software, you acknowledge and agree to the terms of this disclaimer. If you do not agree with these terms, you should refrain from using this software. 