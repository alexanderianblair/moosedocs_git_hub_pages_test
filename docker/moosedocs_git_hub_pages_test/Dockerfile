# Build and test MooseDocsGitHubPagesTest image
# Get base image
FROM alexanderianblair/platypus-deps:main

# By default four cores are used to compile
ARG compile_cores=4

# By default checkout main branch
ARG build_git_sha=main
ARG build_git_repo=alexanderianblair/moosedocs_git_hub_pages_test

# By default we install everything under /opt
ARG WORKDIR=opt

# Get MooseDocsGitHubPagesTest
WORKDIR /$WORKDIR
RUN git clone https://github.com/$build_git_repo
WORKDIR /$WORKDIR/moosedocs_git_hub_pages_test
RUN git checkout $build_git_sha

# Build MooseDocsGitHubPagesTest
WORKDIR /$WORKDIR/moosedocs_git_hub_pages_test
RUN make -j$compile_cores
RUN doxygen doc/content/doxygen/Doxyfile