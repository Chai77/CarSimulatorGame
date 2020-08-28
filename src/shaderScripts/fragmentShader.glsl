#version 450

in vec3 vs_position;
in vec2 vs_tex_coord;
in vec3 vs_color;
in vec3 vs_normal;

out vec3 fs_color;

void main() {
	fs_color = vs_color;
}

