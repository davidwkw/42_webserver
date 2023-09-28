Readme for 42 programme's webserver project

Notes for .conf files:
1. Comments are supported
2. Location needs to be formatted between forward slashes, i.e. /endpoint/
3. root directive should be a relative path to webserv binary, i.e. public/

Footnotes:
1. A combination of chain of responsibility and possibly strategy design pattern would be more ideal for maintainability and scalability.
2. Select used for this implementation but not ideal due to number of fd limitation. A lot more fds are used than expected.
3. May be possible to actually use 1 select/poll/epoll with cgi handling by keeping a duplicate of the socket fd and replacing/dup2-ing the original socket fd with the cgi script input pipe fd after receiving full request body. After the CGI script has completed, dup2 the socket descriptor copy with the descriptor that was previously replaced. If an exception occured while processing the script, handle as usual. Otherwise,
tack on whatever additional headers and write the captured cgi output into the socket descriptor.
4. An additional select is used for CGI script processing to prevent potential read/write blocking. Technically, the select used for the cgi script is used as a tool for inter-process communication rather than client/server communication.
