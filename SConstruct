import excons
from excons.tools import maya
import sys


maya.SetupMscver()


env = excons.MakeBaseEnv()


fbm = excons.Call("fbm", imp=["RequireFbm"])
defs = []
cppflags = ""
customs = [excons.tools.maya.Require, RequireFbm]


if sys.platform == "darwin":
    cppflags += " -Wno-unused-parameter"


prjs = []
prjs.append({"name": "shakeNode",
             "type": "dynamicmodule",
             "ext": maya.PluginExt(),
             "defs": defs,
             "cppflags": cppflags,
             "symvis": "default",
             "incdirs": ["include"],
             "srcs": excons.Glob("src/*.cpp"),
             "custom": customs})


excons.DeclareTargets(env, prjs)
