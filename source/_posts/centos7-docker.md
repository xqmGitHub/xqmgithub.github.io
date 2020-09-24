---
title: CentOS7 安装 Docker 和 Docker-compose
top: 0
date: 2020-05-30 15:26:43
categories: Linux
tags:
- centos
- docker
---

* **安装 Docker**

```
# 安装依赖
sudo yum install -y yum-utils \
  device-mapper-persistent-data \
  lvm2

# 添加docker下载仓库（由于网络原因，这里添加的是阿里云镜像）
sudo yum-config-manager \
    --add-repo \
    https://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo

# 安装docker-ce
sudo yum install docker-ce

# 开机自启
sudo systemctl enable docker
# 启动docker-ce
sudo systemctl start docker

# 验证
sudo docker --version

# 默认情况下，docker 命令会使用 Unix socket 与 Docker 引擎通讯。
# 而只有 root 用户和 docker 组的用户才可以访问 Docker 引擎的 Unix socket。
# 可将非 root 用户 加入 docker 组：（$USER 当前用户）
sudo usermod -aG docker $USER
```

* **安装 docker-compose**

```
# 下载 docker-compose （有可能比较慢 可下载好上传） 版本 1.25.5
sudo curl -L "https://github.com/docker/compose/releases/download/1.25.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose

# 修改权限
sudo chmod +x /usr/local/bin/docker-compose

# 验证
sudo docker-compose --version
```

注意需要使用 root 账户或可以使用 sudo 的账户