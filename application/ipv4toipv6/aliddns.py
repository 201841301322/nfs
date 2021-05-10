#-----------------------------------#
#要安装以下库
#pip install aliyun-python-sdk-core
#pip install aliyun-python-sdk-domain
#pip install aliyun-python-sdk-alidns
#-----------------------------------#
from aliyunsdkcore.client import AcsClient
from aliyunsdkcore.acs_exception.exceptions import ClientException
from aliyunsdkcore.acs_exception.exceptions import ServerException
from aliyunsdkalidns.request.v20150109.DescribeSubDomainRecordsRequest import DescribeSubDomainRecordsRequest
from aliyunsdkalidns.request.v20150109.UpdateDomainRecordRequest import UpdateDomainRecordRequest
import urllib
import os
import time
import json

client = AcsClient('******', '******', 'cn-hangzhou')


def update_record(client,priority,ttl,record_type,value,rr,record_id):
    request = UpdateDomainRecordRequest()
    request.set_accept_format('json')
    request.set_Priority(priority)
    request.set_TTL(ttl)
    request.set_Value(value)
    request.set_Type(record_type)
    request.set_RR(rr)
    request.set_RecordId(record_id)
    response = client.do_action_with_exception(request)
    response = str(response, encoding='utf-8')
    return response


def Describe_SubDomain_Records(client,record_type,subdomain):
    request = DescribeSubDomainRecordsRequest()
    request.set_accept_format('json')

    request.set_Type(record_type)
    request.set_SubDomain(subdomain)

    response = client.do_action_with_exception(request)
    response = str(response, encoding='utf-8')
    relsult = json.loads(response)
    return relsult

def get_internet_ip():
    with urllib.request.urlopen('http://geoip.neu6.edu.cn/') as response:
        html = response.read()
        ip = str(html, encoding='utf-8')
        itstar=ip.find("<p class=\"text-info lead\"> ")
        itend=ip.find(" </p>",itstar)
    return ip[itstar+27:itend]



ip6=get_internet_ip() #获取本机ipv6地址
ym="lhf666.xyz"  #填写你的域名，不用带www

des_relsult = Describe_SubDomain_Records(client,"AAAA",("www."+ym))
des_relsult["TotalCount"]
record_id = des_relsult["DomainRecords"]["Record"][0]["RecordId"]
aaxx=update_record(client,"5","600","AAAA",ip6,"www",record_id)
print(aaxx)



des_relsult = Describe_SubDomain_Records(client,"AAAA",ym)
des_relsult["TotalCount"]
record_id = des_relsult["DomainRecords"]["Record"][0]["RecordId"]
aaxx=update_record(client,"5","600","AAAA",ip6,"@",record_id)
print(aaxx)



