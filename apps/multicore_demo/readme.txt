multicore_demo application
============================

Simple demonstration of starting up secondary CPU cores.


Description
-----------

The multicore_demo application is a demonstration of how to enable secondary cores on those
i.MX6 devices which have more than one Cortex-A9 CPU. It shows how to use the System Reset
Controller peripheral to enable CPU cores. Also, sending a software-generated interrupt to
a specific CPU core is demonstrated.


Requirements
------------

This application only runs on i.MX6Dual/Quad or i.MX6Solo/DualLite chips. It will not run on
the i.MXSoloLite. And, although it will run on the Solo, obviously only a single core is
available.


Build options
-------------

None.


Code organization
-----------------

All code for multicore_demo resides in multicore.c in the src directory.

