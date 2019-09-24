//vert
#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in float tid;
layout (location = 3) in vec4 color;

uniform mat4 projection;
uniform mat4 view = mat4(1.0);
uniform mat4 model = mat4(1.0);

out DATA {
	vec4 position;
	vec2 uv;
	float tid;
	vec4 color;
} vs_out;

void main() {
	gl_Position = projection * view * model * position;
	vs_out.position = model * position;
	vs_out.uv = uv;
	vs_out.tid = tid;
	vs_out.color = color;
}

//frag
#version 330 core

layout (location = 0) out vec4 color;

uniform vec2 light_pos;
//uniform int random;

in DATA {
	vec4 position;
	vec2 uv;
	float tid;
	vec4 color;
} fs_in;

uniform sampler2D textures[16];

void main() {
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);
//	float intensity = 1.0 / length(fs_in.position.xy - light_pos) * random * .08; // flicker
	vec4 textureColor = fs_in.color;
	if (fs_in.tid > 0.0) {
		int tid = int(fs_in.tid - 0.5);
		textureColor = texture(textures[tid], fs_in.uv);
	}
	color = textureColor * intensity;
}
