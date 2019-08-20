---
title: virtualbox 虚拟机静态IP设置（debian）
top: 0
date: 2019-08-17 11:29:29
categories:
tags:
 - virtualbox
 - debian
---

virtualbox 虚拟机静态IP设置（用于Host Only和NAT共存的方式）

网卡1：NAT网络
网卡2：Host-Only网络

sudo vim /etc/network/interfaces

在下面添加

```
# 增加的Host-only静态IP设置 (enp0s8 是根据拓扑关系映射的网卡名称（旧规则是eth0,eth1）)
# 可以通过 ```ls /sys/class/net```查看，是否为enp0s8
auto enp0s8
iface enp0s8 inet static
address 192.168.56.101
netmask 255.255.255.0
gateway 192.168.56.0
```

