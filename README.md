# 🌫️ Mist
<img src="./Mist.png" width="300" align="center">

## ❓ What is it?
***Mist* is a simple x86_64 operating system made for learning how the PC works**
It uses MIT license so you can do anything with this code!

## 🤔 What can it do?
A lot of things. You can see explanation of:
- [Minit](https://github.com/ImLfyz/Mist/tree/main/msc/Minit/Minit.md)
- [Drivers](https://github.com/ImLfyz/Mist/tree/main/msc/drivers/drivers.md)
- [Kernel](https://github.com/ImLfyz/Mist/tree/main/msc/kernel/kernel.md)
- [Mistd](https://github.com/ImLfyz/Mist/tree/main/msc/mistd/mistd.md)
- [Utils](https://github.com/ImLfyz/Mist/tree/main/msc/utils/utils.md)

##  🏁 Get started
***I DON'T recommend to try Mist on real PC. Use QEMU instead***

Also you should have GCC to compile Mist
> **Recommendation**: Use Linux to this

You can start with 2 ways:

Compile by yourself:
- <details>

  - Clone Mist repo:

  ```
  git clone https://github.com/L-fyz/Mist
  ```
  - Compile (Clang):

  ```
  cd ~/Mist
  make
  ```
  - Run with QEMU:

  ```
  make run
  ```

</details>

Use already compiled Mist.img from releases:
- <details>

  - Copy Mist.img:
  ```
  wget https://github.com/L-fyz/Mist/releases/download/v0.8/Mist.img ~/Mist
  ```
  - Run with QEMU:
  ```
  qemu-system-x86_64 -drive format=raw,file=Mist.img -no-reboot
  ```

</details>

## 😰 Issues
***Mist - young project made by schoolboy***

It may contain bugs and errors

If you have one of these, you can visit the [issues](https://github.com/L-fyz/Mist/issues)
Also you can do pull requests with your code. You're welcome!
