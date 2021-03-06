
#version 330 core

layout (location = 0) out vec4 color;

uniform vec2 light_pos;

in DATA {
	vec4 position;
	vec2 uv;
	float tid;
	vec4 color;
} fs_in;

uniform sampler2D textures[16];

void main() {
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);
	vec4 textureColor = fs_in.color;
	if (fs_in.tid > 0.0) {
		int tid = int(fs_in.tid - 0.5);
		textureColor = texture(textures[tid], fs_in.uv);
	}
	color = textureColor * intensity;
}
