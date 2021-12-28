from SCons.Script import *

import os.path
import glob
import winreg
import urllib.request
import zipfile
from pathlib import Path

env = Environment(tools=[])
addonsFolder = r"@AH-64D Apache Longbow\Addons"
pbos = ["fza_ah64_AICrew", "fza_ah64_controls", "fza_ah64_sfmplus", "fza_ah64_us"]
linkablePbos = ["fza_ah64_AICrew", "fza_ah64_controls", "fza_ah64_sfmplus"]

def targetDef(target, description):
    return env.Help(f"\n{target.ljust(20)}\t - {description}")

def allFilesIn(path):
    return [s.replace("$", "$$") for s in glob.glob(path + '/**/*', recursive=True) if os.path.isfile(s)]

def a3toolsPath():
    with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r"SOFTWARE\Bohemia Interactive\Arma 3 Tools") as key:
        return winreg.QueryValueEx(key, "path")[0]

def arma3Path():
    reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
    with winreg.OpenKey(reg, r"SOFTWARE\Wow6432Node\bohemia interactive\arma 3") as key:
        return winreg.EnumValue(key,1)[1]

def addonBuilderPath():
    return os.path.join(a3toolsPath(), "AddonBuilder", "AddonBuilder.exe")

def buildPbo(env, pbo):
    target = os.path.join(addonsFolder, pbo)
    outputPbo = os.path.join(addonsFolder, pbo + ".pbo")
    inputFolder = target
    env.Command(outputPbo, allFilesIn(inputFolder), 
        f'"{addonBuilderPath()}" "{os.path.abspath(inputFolder)}" "{os.path.abspath(addonsFolder)}" -clear -include=buildExtIncludes.txt')
    targetDef(pbo, f"Build the {pbo} pbo.")
    return env.Alias(pbo, outputPbo)

pboAliases = [buildPbo(env, pbo) for pbo in pbos]

env.Command("buildTools", [], Mkdir("buildTools"))

def downloadNaturaldocs(target, source, env):
    url = "https://www.naturaldocs.org/download/natural_docs/2.1.1/Natural_Docs_2.1.1.zip"
    zipFilePath = r"buildTools\NaturalDocs.zip"
    urllib.request.urlretrieve(url, zipFilePath)
    with zipfile.ZipFile(zipFilePath, 'r') as zip_ref:
        zip_ref.extractall(r"buildTools")
    
env.Command(r"buildTools\Natural Docs", [], [downloadNaturaldocs, Delete(r"buildTools\NaturalDocs.zip")])

allPbos = env.Alias("all", pboAliases)
targetDef("all", "Build all pbos.")

env.Command(r"docs\index.html",
    [s for s in allFilesIn(addonsFolder) if s.endswith(".sqf")] + [r"buildTools\Natural Docs"], 
    [Mkdir("docs"), r'"buildTools\Natural Docs\NaturalDocs.exe" naturaldocs'])

env.Alias("docs", r"docs\index.html")
targetDef("docs", "Generate naturaldocs documentation")
env.Help("\n")

env.Clean(["buildTools", "all"], r"buildTools")
env.Clean(["docs", "all"], ["docs", r"naturaldocs\Working Data"])
env.Clean(["all"], [os.path.join(addonsFolder,"fza_ah64_*.pbo"), os.path.join(addonsFolder,"fza_ah64_*.bisign")])

symlinkList = []
try:
    a3dir = arma3Path()
    for pbo in linkablePbos:
        symlinkList.append([os.path.join(a3dir, pbo), os.path.join(addonsFolder, pbo)])
except Exception as e:
    print(f"Error: {e} Couldn't find arma 3, cannot make or remove symlinks")

if (Path("P:").is_dir()):
    for pbo in linkablePbos:
        symlinkList.append([os.path.join("P:/", pbo), os.path.join(addonsFolder, pbo)])
else:
    print("Warning: project drive is not mounted.")

symlinks = env.Alias("symlinks", [], [f'mklink /J "{symlink[0]}" "{symlink[1]}" & exit 0' for symlink in symlinkList])
removeSymlinks = env.Alias("rmsymlinks", [], [f'fsutil reparsepoint delete "{symlink[0]}" & exit 0' for symlink in symlinkList] + [Delete(symlink[0]) for symlink in symlinkList])
env.AlwaysBuild(symlinks)
env.AlwaysBuild(removeSymlinks)

env.Default("all")