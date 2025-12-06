# VSD-Real-World-Edge-AI-Lab  
<details>
<summary>     

## Program tools and Structure    

</summary>  

  
  The program is of 10 days with assignments. VSD Workshops are intense and industry focused and provides latest hardware related programs. Kunal Ghosh Sir, is the person we can reach out for any issues or information related to the program.   

  ![Workshop Flow](Related%20Files/Images%20used%20for%20docs/Flow_of_the_Workshop.jpg)  

---  
### Furthermore for this workshop we have used the following tools:   

- **Freedom Studio**  

Freedom Studio = SiFive’s official Eclipse-based IDE for RISC-V programming and debugging. It is tool used for our project, an Integrated Development Environment (IDE) provided by SiFive for developing software on RISC-V–based processors.    
✅ What Freedom Studio Includes

- A customized Eclipse-based IDE
- GNU GCC toolchain for RISC-V
- OpenOCD for debugging
- SDKs for SiFive Freedom platforms
- Also, Support for writing, building, and debugging C/C++ applications on RISC-V cores

✅ Where It Is Used

 <li>RISC-V learning and experimentation
 Edge AI or embedded system development (if using RISC-V boards)
 Programming SiFive boards such as HiFive1, HiFive Unleashed, etc.
</li>









</details>
  
##  Execution of the Program Flow

1. Setting Up the Environment.

We used GitHub codespace for cloud based lab. The steps are simple as follows:

	1.Open the git hub link provided by svsd: 
	https://www.google.com/url?q=https%3A%2F%2Fgithub.com%2Fvsdip%2Fvsd-riscv-edgeai&sa=D&source=calendar&usd=2&usg=AOvVaw20wToBO54VOtgHuwE3Bo2n
	2.Click on green code button and find out the create codespace on main option.
	3.Wait for a few seconds and VSCode like tab will open.
	4. Now find the Internet symbol within Ports and forwarded address so, to open noVNC 	   Desktop.
	5. As we step into the environment (as seen in the image below) and have opened the novnc webpage, we can add the following commands:  

```
#To change the directory to the Freedom Studio's Directory
cd ~/Desktop/FreedomStudio-3-1-1
#Opening the Freedom Studio
./FreedomStudio 3-1-1

```
  
Output would be:

![add a caption ](Related%20Files/Images%20used%20for%20docs/1.2.png) 
![add a caption ](Related%20Files/Images%20used%20for%20docs/1.3.png)  
 
6. After that I click on vnc.html inside the webpage as seen in the fourth image just above. And click on connect.  

![add a caption ](Related%20Files/Images%20used%20for%20docs/1.4.png) 
![add a caption ](Related%20Files/Images%20used%20for%20docs/1.5.png)   

7. Once the session gets connected and opened, go to the freedom studio folder present in the homepage, and open Freedom Studio from there, I had modified the workspace directory, to the default `/home/vscode/Desktop`. 

![add a caption ](Related%20Files/Images%20used%20for%20docs/1.6.png)   

![add a caption ](Related%20Files/Images%20used%20for%20docs/1.7.png)  

8. After exploring the option select I'm done here, take me to the workbench and we will proceed with our second part of this section where we will make example project in the eclipse IDE.    

![add a caption ](Related%20Files/Images%20used%20for%20docs/1.6.png)     
---
 <details>    

 9. Tips for Smooth Operation    


* Use a Chromium-based browser (Chrome or Edge) for better VNC responsiveness.
* Avoid closing the Codespace tab while FreedomStudio is running.
* All files in /home/vscode/Desktop persist while the Codespace is active.
* If the desktop view appears blank, refresh the noVNC tab once after the Codespace boots.  

10. Troubleshooting     

```
#Sourced from #https://github.com/vsdip/vsd-riscv
-edgeai

Issue Port 6080 does not appear	
Solution Wait for setup to complete (~2–3 min). Refresh PORTS tab.  

noVNC window is blank
Refresh browser tab or reopen from PORTS list.  

FreedomStudio not found	Run 
setup manually or restart Codespace.  

Workspace prompt reappears each time	  
Select "Use this as default and do not ask again" before launching.</details>   


```
---  
  
 2. Example project on the Eclipse IDE. 
(coming soon), feel free to explore other project related directories present here.
  


