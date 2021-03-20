#pragma once

#if defined(_WIN32) && !defined(inet_ntop)
const char* inet_ntop(int af, const void* src, char *dst, size_t size)
{
	struct sockaddr_in server_addr;

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = af;
	memcpy(&server_addr.sin_addr, src, sizeof(server_addr.sin_addr));


	DWORD dst_len = size;

	// Windows XP doesn't support inet_ntop.
	if(WSAAddressToStringA((struct sockaddr *)&server_addr, sizeof(sockaddr_in), nullptr, dst, &dst_len) != 0) {
		return dst;
	}
	else {
		return NULL;
	}
}
#endif
