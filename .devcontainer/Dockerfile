# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.154.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here> 
RUN apt-get -y update
# RUN apt-get -y install clangd-11
# RUN sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-11 100