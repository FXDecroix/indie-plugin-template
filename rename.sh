#!/usr/bin/env bash
# Renames this template's plugin identity in CMakeLists.txt.
# Usage: ./rename.sh ProjectName "Product Name" com.company.product MnfC Plgc
set -euo pipefail

project_name="$1"
product_name="$2"
bundle_id="$3"
manufacturer_code="$4"
plugin_code="$5"

sed -i.bak \
    -e "s/set(PROJECT_NAME \"IndiePluginTemplate\")/set(PROJECT_NAME \"${project_name}\")/" \
    -e "s/set(PRODUCT_NAME \"Indie Plugin Template\")/set(PRODUCT_NAME \"${product_name}\")/" \
    -e "s/set(BUNDLE_ID \"com.drfixaudio.indieplugintemplate\")/set(BUNDLE_ID \"${bundle_id}\")/" \
    -e "s/PLUGIN_MANUFACTURER_CODE Drfx/PLUGIN_MANUFACTURER_CODE ${manufacturer_code}/" \
    -e "s/PLUGIN_CODE Tmpl/PLUGIN_CODE ${plugin_code}/" \
    -e "s/PRODUCT_NAME_WITHOUT_VERSION=\"Indie Plugin Template\"/PRODUCT_NAME_WITHOUT_VERSION=\"${product_name}\"/" \
    CMakeLists.txt
rm -f CMakeLists.txt.bak
