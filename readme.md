<html>
<head>
<title>Intrafoundation.NetworkDiscovery.1 COM v1.3</title>
</head>

<body>

<div><strong><a href="http://www.intrafoundation.com/software/networkdiscovery.htm">I n t r a f o u n d a t i o n . N e t w o r k D i s c o v e r y . 1</a></strong></div>
<div><!--C# .NET and -->C++ ATL COM Component</div>
<div>FOR <a href="http://www.microsoft.com">ASP</a> and <a href="http://www.adobe.com">ColdFusion</a></div>
<div><small>Open Source <!--64-bit .NET and -->64 and 32-bit C++ COM Object</small></div>


<tt><strong>v1.3, August 30th 2012</strong></tt><br>
<small>
<a href="http://www.intrafoundation.com">http://www.intrafoundation.com</a><br>
<a href="mailto:webmaster@intrafoundation.com">webmaster@intrafoundation.com</a><br>
</small>



<div style="background-color: #f0f020; font-size: 9pt; text-align: center; margin: 1px; padding: 3px;">
<strong>NOTICE:</strong> This software is now <b>64-bit</b>. If you need <b>32-bit</b> builds, they are located in the <tt>32bit_versions\</tt> folder.
</div>
<div style="background-color: #f0f060; font-size: 9pt; text-align: center; margin: 1px; padding: 3px;">
<b>NEW:</b> Follow the open source development of this software at <a href="https://github.com/lasellers">lasellers @ github.com</a>
or <a href="http://www.codeplex.com/site/users/view/lasellers">lasellers @ codeplex.com</a>.
</div>



<!-- DESCRIPTION -->
<p class=firstpara>
The COM object <strong>NetworkDiscovery</strong> was designed to be used in conjunction with <a href="http://www.intrafoundation.com/software/udpclient.htm">UDPClient</a> and/or <a href="http://www.intrafoundation.com/software/tcpclient.htm">TCPClient</a>.
It is a network discovery tool, which, among other things, can tell you the name of all computers currently on your local area network.
(Before you can query other computers on a network, your first step is generally determine which computers are there -- their name and IP addresses.)
</p>
<p>
A COM object
(for those of you who are using this software who are not web developers but hardcore gamers)
is a type of .DLL.
This particular type is the kind that makes up most of the code that powers the Windows Operating System itself.
They are essentially self-contained ("encapulated, object-oriented" in tech-speak) programs.
Many of the applications you may use (the .EXE files) will make use of COM objects that it brings with it or that are included with the Windows Operating System.
</p>




<br>
<br>
<br>
<h3>REQUIREMENTS / SERVER PLATFORMS</h3>
<p>
This COM object was originally designed on and for Windows 2000 Professional and Windows XP Professional.
The 2012 version and up was rebuilt on Windows 7 64-bit.
It has not been tested under Windows 95, 98, ME or NT 3.51/4.
Nevertheless, it may work under some of them.
</p>
<p>
Additionally you most typically will need either <a href="http://www.adobe.com">Adobe ColdFusion</a> or <a href="http://www.microsoft.com">Microsoft ASP</a> installed.
If you don't know what either of these are... 
then you're going to need to make friends with a geeky web developer somewhere to help you.
</p>
<p>
You should be able to use the COM from:
<ul>
<li>Adobe <a href="http://www.Adobe.com">ColdFusion</a>
<li>Microsoft <A href="www.microsoft.com">ASP</a>
<li><a href="http://www.php4.net">PHP4</a>
<li>Any other engine or compiler that can use COM objects.
</ul>
</p>



<br>
<br>
<br>
<h3>COPYRIGHT / TERMS OF USE</h3>
<p>
This software is Copyright (c) 2004 by Lewis A. Sellers.
It is not public domain, nor is it GPL'ed, but it is very close.
As long as you do not modify any files in the archive, nor add to them, nor delete any of them,
and do not charge for access to said archive you may redistribute the archive as you like.
</p>
<p>
You may use this software as-is with any software you wish, so long as said
archive is included unmodified with proper credits and link to it's homesite is included also
(<a href="http://www.intrafoundation.com/software/networkdiscovery.htm">http://www.intrafoundation.com/software/networkdiscovery.htm</a>).
</p>
<p>
You may modify and use the source code as you like -- with the understanding
that if you do, you still have to include the original, unaltered archive as
well as the aforementioned credits and link.
</p>
<p>
You may use this software in commerical applications, whether closed-source or open-source so long as the aforementioned unaltered archive is included with the application
and the aforementioned creditation and hyperlink are included.
</p>
<p>
If this software is used in a released project or included in a publication you are to make reasonable efforts to contact the author and notify them as to such.
The author of this software has a primary email address of: <a href="mailto:webmaster@intrafoundation.com">webmaster@intrafoundation.com</a>.
</p>
<p>
You use this software at your own risk.
</p>



<br>
<br>
<br>
<h3>INSTALLATION</h3>
<p>
The COM object itself is the file called <tt>NetworkDiscoverycom.dll</tt>.
To install it, at the command prompt type: <tt>regsvr32 NetworkDiscoverycom.dll</tt>.
You may first wish to copy it to your project folder or some other folder you make just for it.
</p>
<p>
The precompiled file <tt>NetworkDiscoverycom.dll</tt> is root folder of the archive.
</p>
<p>
There are install.bat and uninstall.bat files included that you can simply click from Windows which will do the same.
</p>



<br>
<br>
<br>
<h3>UNINSTALLATION</h3>
<p>
At the command prompt type: <tt>regsvr32 /u NetworkDiscoverycom.dll</tt>.
Or see above.
</p>



<br>
<br>
<br>
<h3>THE EXAMPLE SCRIPTS</h3>
<p>
There are several example scripts included with this COM object.
Some are only partially done.
None are optimised for the protocols they use.
Addtionally, some are written by the author(s) of this software, whlie others have been developed by it's users.
</p>
<p>
For most of the examples you'll need to have the appropriate SERVER software installed on your local computer
(i.e., either ASP or ColdFusion).
</p>
<p>
You might want to look at the source of the scripts before you use them.
</p>

<br>
<p>
<em>Send in your own sample scripts.</em>
</p>




<br>
<br>
<br>
<h3>COMMAND OVERVIEW : MAKING IT WORK</h3>

<p>
Well, assuming you installed/registered the COM object and on the same machine you've got ColdFusion or ASP installed then all you need to do is...
open your browser to this web page and click on any of the examples to see it in living action.
(On the server... not as a file. That is with "HTTP://" prepended not "FILE://". But I really hope you knew that already.)
</p>
<p>
Assuming you've seen the examples and are now suitably excited about bringing this kind of thing to your own web pages -- read on.
</p>
<p>
Basically all there is to using this COM object is call the function your interested in and parse the results.
</p>
<p>
There are several other useful properties you can look at or set that can be used for error handling and tweaking overall performance.
</p>


<br>
<br>
<br>
<h1>METHODS</h1>

<table border=1 align=right class=function>
<tr><th colspan=3>METHODS</th></tr>
<tr><th>NAME</th><th>IN</th><th>OUT</th></tr>
<tr><td>Computer</td><td></td<td>string</td></tr>
<tr><td>ComputerIP</td><td></td<td>string</td></tr>
<tr><td>NetworkComputers</td><td></td><td>comma separated value string</td></tr>
<tr><td>NetworkComputersIP</td><td></td><td>comma separated value string</td></tr>
<tr><td>ClearLog</td><td></td<td></td></tr>
</table>
<br clear=right>


<h4>Computer</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>string</td></tr>
</table>
<p>
This function returns the ASCII network name of the local computer.
Examples would be "HORACE", "JEDI", etc.
</p>


<h4>ComputerIP</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>string</td></tr>
</table>
<p>
This function returns the network ip of the local computer.
Examples would be "127.0.0.1", "192.168.0.1", etc.
</p>


<h4>NetworkComputers</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>comma separated string of computer names</td></tr>
</table>
<p>
This function does a NetBIOS query of the local network and returns a list of all computers which respond.
Generally this means that it returns a list of every computer currently on the same hub, switch, router, etc as yours.
The return is a comma separated list. 
</p>
<p>
Extremely useful in gaming situations, etc where you which to auto-detect all computers as they plug into the network etc.
</p>
<p>
Returns the ASCII name of the computers. An examples would be "HORACE,JEDI,JOHNC,MARINE", etc.
</p>


<h4>NetworkComputersIP</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>comma separated string of computer ips</td></tr>
</table>
<p>
This function does a NetBIOS query of the local network and returns a list of all computers which respond.
Generally this means that it returns a list of every computer currently on the same hub, switch, router, etc as yours.
The return is a comma separated list. 
</p>
<p>
Extremely useful in gaming situations, etc where you which to auto-detect all computers as they plug into the network etc.
</p>
<p>
The list of all computer IPs is returned.
An example would be "192.168.0.1,192.168.0.2,192.168.0.32,192.168.0.212", etc.
</p>


<h4>ClearLog</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td></td></tr>
</table>
<p>
Clears out the error log.
</p>




<br>
<br>
<br>
<h1>PROPERTIES</h1>


<p>
All properties are optional.
They can be extremely useful for optimizing the performance of your code however,
particular where high-performance, highly-responsive operation is required.
</p>


<h3>PUT</h3>
<table border=1 align=right class=function>
<tr><th colspan=2>PROPERTIES (PUT)</th></tr>
</table>
<br clear=right>


<h3>GET</h3>
<table border=1 align=right class=function>
<tr><th colspan=2>PROPERTIES (GET)</th></tr>
<tr><td>thread</td><td></td><td>number</td></tr>
<tr><td>version</td><td></td><td>string</td></tr>
<tr><td>copyright</td><td></td><td>string</td></tr>
<tr><td>description</td><td></td><td>string</td></tr>
<tr><td>instance</td><td></td><td>number</td></tr>
<tr><td>instances</td><td></td><td>number</td></tr>
<tr><td>Log</td><td></td><td>string</td></tr>
</table>
<br clear=right>



<h4>description</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>string</td></tr>
</table>
<p>
Description of this COM object.
</p>

<h4>copyright</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>string</td></tr>
</table>
<p>
The copyright notice.
</p>

<h4>version</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The current version number.
</p>

<h4>Log</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Gets list of all error messages logged since the object was created.
Clear out the error log with the ClearLog method.
</p>


<h4>instance</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>number</td></tr>
</table>
<p>
If you code calls several instances of this COM into existance at once you can determine which instance you are talking to by calling this.
</p>
<p>
This is an integer number, where the default first instance is always numbered "1".
</p>


<h4>instances</h4>
<table class=function>
<tr><th>parameters</th><td><td></tr>
<tr><th>returns</th><td>number</td></tr>
</table>
<p>
See "instance".
Calling this returns the number of instances of this COM object that have been called into existance since your server has been rebooted.
</p>
<p>
Note: When using this COM in desktop software the instance number will reset itself when the software is closed and restarted.
When used in sever-side software, as long as the COM stays loaded in memory, then every time the COM is called the instances number will increase by one.
</p>
<p>
Instances/Instance are mainly of use with debugging/optimizing the COM instantation process.
</p>
<p>
This is an integer number, where the default first instance is always numbered "1".
</p>




<br>
<br>
<br>
<h1>VERSION HISTORY</h1>

<ul>

<li><b>1.3</b> August 30th 2012.
<p>
Compile for 64-bit support in addition to 32-bit.
</p>
<p>
For unknown reasons the separate <tt>classes\</tt> folder with common code between this a  few other projects was not bundled in the last uploaded version of this app. Thus, I have had to pull it from other sources. The various files were slightly out of temporal sync, thus I've had to rebuild the project more from scratch than anticipated.</p><p>
The 1.3 version pulls some of its sources from a partial port to Macintosh OS X I did years ago but never released.</p><p>
From now on, each project keeps it's own separate copy of any shared files.
Especially important given that it is going to be released on github and codeplex.
</p>
<p><b>This version should be considered possibly unstable as it has not been extensively retested.</b></p>
<p><b>TO DO:</b>
Make C# COM interop .NET DLL or perhaps pinvoke a c wrapped version.
Not interested in using C++/CLI.
</p>
</li>


<li><b>1.2</b> November 5th 2004.
<p>
Updated the C++ classes it shares with several other projects, so recompiled.
Cleaned up for the relaunch of the <a href="http://www.intrafoundation.com">Intrafoundation</a> web site.
</p>
</li>

<li><b>1.1</b> August 25th 2004.
<p>
Changed name from NetworkTopology to NetworkDiscovery so as not to clash with old naming scheme of IHS/IHTK.
Also did a small amount of preventative debugging work while I was at it.
</p>
</li>

<li><b>1.00</b> July 6th 2004.
<p>
This was part of unreleased versions of udpclient and tcpclient for a while.
</p>
<p>
As you might have guessed (or hoped) as time permits this COM object with gather several new, powerful functions which will generate fairly detailed network topology maps -- or at least that's the ultimate purpose.
</p>
</li>

</ul>
<!-- END DESCRIPTION -->


<br clear=all>
<hr>
<div align=right>
Intrafoundation Software<br>
<small><tt>Making Atomic Warfare Fun Again</tt></small><br>
<br clear=all>
</div>

</body>
</html>
