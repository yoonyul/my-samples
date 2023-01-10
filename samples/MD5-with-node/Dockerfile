FROM node:lts-alpine3.17
MAINTAINER lqq
COPY ./MD5 /MD5/
CMD ["node","--experimental-wasm-threads","--experimental-wasm-bulk-memory","/MD5/http.js"]
