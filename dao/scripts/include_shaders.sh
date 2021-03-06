#!/bin/sh

#  include_shaders.sh
#  dao
#
#  Created by Richard Bell on 9/20/19.
#  Copyright © 2019 apocryphal. All rights reserved.


echo "--Begin Shader Source Copy--"

SHADER_FILE="$PROJECT_DIR/dao/src/graphics/shaders/ShaderSource.h"
echo "/* Generated by $0 */" > $SHADER_FILE
echo "#pragma once\n" >> $SHADER_FILE
echo "#include <string>\n" >> $SHADER_FILE
echo "namespace dao { namespace graphics { namespace shaders {\n" >> $SHADER_FILE

for entry in `ls $PROJECT_DIR/dao/src/shaders | grep '.glsl'`; do
	varname=`echo $(basename $entry) | cut -f 1 -d '.'`
	echo "const std::string $varname = R\"(" >> $SHADER_FILE
	cat $PROJECT_DIR/dao/src/shaders/$entry >> $SHADER_FILE
echo ')";\n' >> $SHADER_FILE
done

echo "}}}" >> $SHADER_FILE
