#include <iostream>
#include <windows.h>
#include <string>

std::string ReadRegistryKey(HKEY hKeyRoot, const std::string& subKey, const std::string& valueName) {
    HKEY hKey;
    char value[256];
    DWORD valueLength = sizeof(value);
    DWORD type = 0;
    if (RegOpenKeyExA(hKeyRoot, subKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        return "";
    }
    if (RegQueryValueExA(hKey, valueName.c_str(), nullptr, &type, (LPBYTE)value, &valueLength) != ERROR_SUCCESS || type != REG_SZ) {
        RegCloseKey(hKey);
        return "";
    }
    RegCloseKey(hKey);
    return std::string(value, valueLength - 1);
}

void ShowErrorDialog() {
    MessageBoxA(nullptr, "Wrong key or cannot access the key.", "Error", MB_ICONERROR | MB_OK);
}

int main() {
    std::string storedPassword = ReadRegistryKey(HKEY_LOCAL_MACHINE, "Software\\SecureSethc", "Key");
    if (storedPassword.empty()) {
        std::cerr << "Error: Wrong key or cannot access the key." << std::endl;
        return 1;
    }

    std::string inputPassword;
    std::cout << "Enter password: ";
    std::getline(std::cin, inputPassword);

    if (inputPassword == storedPassword) {
        std::cout << "Welcome" << std::endl;
        system("cmd.exe");
    }
    else {
        std::cerr << "Error: Wrong key or cannot access the key." << std::endl;
        ShowErrorDialog();
    }

    return 0;
}
