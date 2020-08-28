#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 tex_coord;
layout (location = 2) in vec3 color;
layout (location = 3) in vec3 normal;

out vec3 vs_position;
out vec2 vs_tex_coord;
out vec3 vs_color;
out vec3 vs_normal;

void main() {
	gl_Position = vec4(position, 1.f);
	
	vs_position = position;
	vs_tex_coord = tex_coord;
	vs_color = color;
	vs_normal = normal;
}