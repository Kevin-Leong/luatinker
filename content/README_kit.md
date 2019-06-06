<div align="right">
<a href="https://github.com/losophy/raindrop/blob/master/README.md">  about</a>
</div> 

<br>

<b><details><summary>vim</summary></b>

Some acticles

</details>

<b><details><summary>grep</summary></b>

Some acticles

</details>

<b><details><summary>gdb</summary></b>

cmd:gdb<br>
gdb$ file yourpram

* save commands history<br>
echo 'set history save on' >> ~/.gdbinit && chmod 600 ~/.gdbinit<br>
gdb$ show history

* set parameter<br>
gdb$ set args(e.g. set args 10 20 30 40 50)<br>
gdb$ show args<br>

* start<br>

* break<br>
gdb$ b gdb_test.c:3 <br>
gdb$ info b
 
 * print<br>
gdb$ p i<br>
gdb$ p/x i
 
 * UI interface(TUI mode) <br>
ctrl+X+A

</details>

<b><details><summary>git</summary></b>

Some acticles

</details>

<b><details><summary>wc</summary></b>

Some acticles

</details>

<b><details><summary>netstat</summary></b>
# judge the health of the connection
netstat -anp | grep xxxx<br>
netstat -anp | grep pid<br>

netstat -n | awk '/^tcp/ {++S[$NF]} END {for(a in S) print a, S[a]}'<br>
```
LAST_ACK 5  
SYN_RECV 30  
ESTABLISHED 15  
FIN_WAIT1 51  
FIN_WAIT2 5  
TIME_WAIT 10  
```

</details>

<b><details><summary>pstack</summary></b>

Some acticles

</details>

<b><details><summary>os</summary></b>

# os information
lsb_release -a
```
No LSB modules are available.
Distributor ID: Ubuntu
Description:    Ubuntu 16.04.5 LTS
Release:        16.04
Codename:       xenial
```
uname -a
```
Linux coding.ide 3.10.107-1-tlinux2_kvm_guest-0046.cd.nosign #1 SMP Wed Jan 31 15:25:12 CST 2018 x86_64 x86_64 x86_64 GNU/Linux
```
</details>
