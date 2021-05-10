本仓库作用：python进行阿里云的ddns解析和socat的ip4v转ipv6 -lhf

python3 setup.py build   python对库的安装
python3 setup.py install  python对库的安装
先对setuptool工具进行安装
再安装pip
安装完pip再更新一下pip 可以用pip-20.1-py2.py3-none-any
python pip-20.1-py2.py3-none-any.whl/pip install pip-20.1-py2.py3-none-any.whl
然后安装py库(安装时可以在后面加 -i https://mirrors.aliyun.com/pypi/simple/ )
#pip install aliyun-python-sdk-core
#pip install aliyun-python-sdk-domain
#pip install aliyun-python-sdk-alidns


编译arm版本socat
1、./configure   --host=x86_64   CC=arm-linux-gcc(这里填你交叉编译器gcc)   --prefix=$PWD/arm
2、make
3、make  install
4、然后把socat拷贝到arm板上
5.nohup socat -d -d -lf /var/log/socat.log TCP6-LISTEN:8080,reuseaddr,fork TCP4:192.168.123.114:8080 &
这是把192.168.123.114的8080端口映射到本机ip6的8080端口

注：
【1】
在安装pip install aliyun-python-sdk-core要是遇到这种错误
building wheel for subprocess32 (setup.py) 和 running setup.py install for subprocess32 ... error

第一个安装gcc和g++编译器

sudo apt-get install build-essential

sudo apt-get install python-dev

第二个 

sudo apt-get install -y python-subprocess32


【2】
padavan下发ipv6地址：
modprobe ip6table_mangle
ebtables -t broute -A BROUTING -p ! ipv6 -j DROP -i eth2.2
brctl addif br0 eth2.2
