#include <iostream>

#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{

    struct ifaddrs *addresses;
    if (getifaddrs(&addresses) == -1)
    {
        cout << "addressed failed" << endl;
        return 0;
    }
    while (addresses)
    {

        int family = addresses->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6)
        {
            cout << addresses->ifa_name << " " << family << " " << endl;
            char ap[100];
            const int family_size=family ==AF_INET ? sizeof(      struct sockaddr_in):sizeof(struct sockaddr_in6) ;                   
            getnameinfo(addresses->ifa_addr,family_size,ap,sizeof(ap),0,0,NI_NUMERICHOST);
            cout << addresses->ifa_name << " " << family << " " <<"  " <<ap<<endl;
            
        }
        addresses = addresses->ifa_next;
    }
}

/*
lo 2 
lo 2   127.0.0.1
eth0 2 
eth0 2   10.0.2.15
eth1 2 
eth1 2   192.168.0.100
eth2 2 
eth2 2   192.168.56.101
lo 10 
lo 10   ::1
eth0 10 
eth0 10   fe80::a00:27ff:fe81:2d4c%eth0
eth1 10 
eth1 10   fe80::a00:27ff:fe86:49f0%eth1
eth2 10 
eth2 10   fe80::a00:27ff:fed5:a6e3%eth2
eth3 10 
eth3 10   fe80::a00:27ff:fe18:ee54%eth3
*/