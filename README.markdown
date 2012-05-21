mktokens
========

Generate node tokens for a RandomPartitioner-equipped Cassandra cluster.

Build / Install
---------------
You need [GMP](http://gmplib.org), (package `libgmp-dev` on Debian
systems).  Afterward, simply run `make`, and optionally `make install`.

Usage
-----
    Usage: mktokens <num_tokens>

<code>mktokens</code> accepts one (mandatory) argument for the number of
tokens to generate.

About
-----
This is trivial, obviously, but after cobbling it together for purposes
of playing with [GMP](http://gmplib.org), it occured to it was a)
something I had a reoccurring need for, and b) that might prove useful to
someone else (as an example of libgmp usage if nothing else).
