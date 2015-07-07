====================================
What’s included in the package
====================================

Telerik UI for iOS package creates a folder named “Telerik” at your Documents directory. There you can find “UI for iOS“ folder that contains:

- README.txt - a ReadMe file which will quickly inform you about what is contained in the package and how to use it.
- TelerikUI.framework - Telerik UI for iOS framework.
- Documentation - a DocSet and Html documentation.
- TelerikUIExamples - there you can find a comprehensive set of examples that you can run on iPhone, iPad and iPod Touch.
- EULA.rtf - containing the End-User License Agreement.
- xcodeinstall.command - a script that installs the TelerikUI.framework and the DocSet in Xcode. By default, this is done by the package. 
- xcodeuninstall.command - uninstalls TelerikUI.framework and Telerik DocSet from Xcode.

==================================
Getting started
==================================

———————————————————————
TelerikUI.framework
——————————————————————-
1. Create a new project in Xcode.
2. Select the project in the project explorer.
3. Select the General section from the main view.
4. Click the “+” button in the Linked Frameworks and Libraries.
5. Select TelerikUI.framework that should appear under the Developer Frameworks folder.


If you do not find it there, you can use the xcodeinstall.command file to install it. In case you are not the Administrator of the machine and installing the TelerikUI.framework is not allowed, you can:

6. Click “Add Other…” button and navigate to Documents\Telerik\UI for iOS\TelerikUI.framework

Now you can start using the Telerik UI for iOS types following our documentation.

——————————————————————-
Documentation
——————————————————————-

For your convenience, Telerik UI for iOS distributes two types of documentation, allowing you to follow whichever type you find more suitable:

- Html documentation. You can find this documentation at Documents\Telerik\UI for iOS\html. Here you can start with index.html that will give you a flat index of all guides and API and hierarchy.html that will give you a hierarchical view of the guides and API.
- DocSet. This documentation type is integrated with Xcode. A convenient viewer for that type of documentation is Dash: http://kapeli.com/dash 

—————————————————————-
Examples
—————————————————————-

The TelerikUIExamples project that you can find at Documents\Telerik\UI for iOS\TelerikUIExamples will allow you quickly and easily to get up to speed with Telerik UI for iOS feature set and usage. Quickly change a parameter and test the results or directly get a code snippet and incorporate it in your project.

=======
License
=======

This product is licensed under Telerik End User License Agreement for UI for iOS
license which can be found at Documents\Telerik\UI for iOS\eula.rtf
