# SecureSethc
Spawn a command prompt as SYSTEM from logon screen while protecting against unauthorized access. This is useful for gaining quick access to SYSTEM account, recovering your user profile if you brick it, you want to change a file before logging on (e.g. ThrottleStop ini, etc). Normally, people just replace "sethc.exe" with the command prompt for that issue, but then anyone with physical access to your PC can gain full control. This fixes that problem.

Take ownership of the sethc.exe and change its permissions, rename it to sethc.exe.bak
Make registry folder: HKEY_LOCAL_MACHINE\SOFTWARE\SecureSethc
And add registry entry (REG_SZ) named "Key" with your desired password

![Screenshot](https://github.com/user-attachments/assets/7626e4f3-c817-47c0-b602-0f72ae0a8e1f)

![ss2](https://github.com/user-attachments/assets/efde2799-01f6-409e-9cbf-cb99d02e5c68)
