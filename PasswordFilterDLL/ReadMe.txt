PasswordFilter for windows

special thank's Yevgeny Menaker http://www.devx.com/security/Article/21522

Requirements: Visual C++ Redistributable for Visual Studio 2015 (https://goo.gl/tfO8xB)

Install and register a Windows password filter DLL:

Copy the PasswordFilterRegExp.dll to the Windows installation directory on the domain controller or local computer. On standard installations, the default folder is \Windows\System32. Make sure that you create a 32-bit password filter DLL for 32-bit computers and a 64-bit password filter DLL for 64-bit computers, and then copy them to the appropriate location.
To register the password filter, update the following system registry key:  HKEY_LOCAL_MACHINE\ SYSTEM\ CurrentControlSet\ Control\ Lsa\ Notification Packages 
If the Notification Packages subkey exists, add the name of your PasswordFilterRegExp.dll to the existing value data. Do not overwrite the existing values, and do not include the .dll extension.
If the Notification Packages subkey does not exist, add it, and then specify the name of the DLL for the value data. Do not include the .dll extension.
The Notification Packages subkey can add multiple packages.
Add registry key for regular expression. (/Regestry/PasswordFilterKenSoft.reg)

NOTE!
On 64 Bit systems, you must copy the dynamic link library to both the "sysWOW64" and "System32" directories. In other words, both directories need the "Passfilt.dll" library.

Error event below if not put in right locations;

Log Name:      System
Source:        Microsoft-Windows-Directory-Services-SAM
Date:          25/10/2016 20:22:04
Event ID:      16953
Task Category: None
Level:         Error
Keywords:      
User:          SYSTEM
Computer:      WIN-8HLNLTB7VBR.acme.local
Description:
The password notification DLL pfilt failed to load with error 126. Please verify that the notification DLL path defined in the registry, HKLM\System\CurrentControlSet\Control\Lsa\Notification Packages, refers to a correct and absolute path (<drive>:\<path>\<filename>.<ext>) and not a relative or invalid path. If the DLL path is correct, please validate that any supporting files are located in the same directory, and that the system account has read access to both the DLL path and any supporting files.  Contact the provider of the notification DLL for additional support. Further details can be found on the web at http://go.microsoft.com/fwlink/?LinkId=245898.
Event Xml:
<Event xmlns="http://schemas.microsoft.com/win/2004/08/events/event">
  <System>
    <Provider Name="Microsoft-Windows-Directory-Services-SAM" Guid="{0D4FDC09-8C27-494A-BDA0-505E4FD8ADAE}" />
    <EventID>16953</EventID>
    <Version>0</Version>
    <Level>2</Level>
    <Task>0</Task>
    <Opcode>0</Opcode>
    <Keywords>0x8000000000000000</Keywords>
    <TimeCreated SystemTime="2016-10-25T19:22:04.943304700Z" />
    <EventRecordID>1550</EventRecordID>
    <Correlation />
    <Execution ProcessID="524" ThreadID="528" />
    <Channel>System</Channel>
    <Computer>WIN-8HLNLTB7VBR.acme.local</Computer>
    <Security UserID="S-1-5-18" />
  </System>
  <EventData Name="SAMMSG_NOTIFICATION_PACKAGE_REGISTRATION_FAILED">
    <Data Name="NotificationPackage:">pfilt</Data>
    <Data Name="Registry key:">HKLM\System\CurrentControlSet\Control\Lsa\</Data>
    <Data Name="Registry value:">Notification Packages</Data>
    <Data Name="Error code:">126</Data>
  </EventData>
</Event>

ref::
https://github.com/krajster
https://github.com/krajster/PasswordFilter

reads from file
https://github.com/shaellancelot/PasswordFilter

https://passfilt.codeplex.com/SourceControl/latest#PassFilt/PassFilt/PassFilt.h

using it for bad
https://phocean.net/2013/10/02/password-stealing-using-a-password-filter.html

had to switch from MDd to MTd

https://blogs.msdn.microsoft.com/spatdsg/2005/12/27/debugging-lsass-oh-what-fun-it-is-to-ride/
https://blogs.msdn.microsoft.com/alejacma/2007/11/13/how-to-debug-lsass-exe-process/