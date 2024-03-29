#ifndef SOCKET_H_
# define SOCKET_H_

class	Socket
{
public:
	virtual				~Socket() {} ;
	virtual bool		bindSocket() = 0;
	virtual void		listenSocket() = 0;
	// Accepte les clients en recreeant une socket contenant les infos necessaires
	virtual Socket*		acceptSocket() = 0;
	// Ecrit les len bytes du buffer buf sur la socket
	virtual int			sendSocket(void* buf, int len) = 0;
	// Lit de len bytes sur la socket dans le buffer buf
	virtual int			recvSocket(void* buf, int len) = 0;
	// Renvoie la socket associee
	virtual int			getSocket() = 0;
	// Renvoie la limite de File Descriptors
	virtual int			getLim() = 0;
	virtual void		close() = 0;
};

# ifdef _WIN32
#  include "SocketWindows.h"
#  define ABSSOCKET SocketWindows
# else
#  include "SocketUnix.h"
#  define ABSSOCKET SocketUnix
# endif

#endif // SOCKET_H_
