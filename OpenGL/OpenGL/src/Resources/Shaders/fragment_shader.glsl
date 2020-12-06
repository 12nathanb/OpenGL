#version 440

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuseTex;
	sampler2D specularTex;
};

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_normal;

out vec4 fs_color;

uniform Material material;

uniform sampler2D texture0;

uniform vec3 lightPos0;
uniform vec3 cameraPos;

void main()
{
	//fs_color = vec4(vs_color, 1.0f);

	//ambient light
	vec3 ambientLight = material.ambient;

	//diffuse light
	vec3 posToLightDirVec = normalize(lightPos0 - vs_position);
	vec3 diffuseColor = vec3(1.f,1.f,1.f);
	float diffuse = clamp(dot(posToLightDirVec, vs_normal), 0, 1);
	vec3 diffuseFinal = material.diffuse * diffuse;

	//specular Light
	vec3 lightToPosDirVec = normalize(vs_position - lightPos0);
	vec3 reflectDirVec = normalize(reflect(lightToPosDirVec, normalize(vs_normal)));
	vec3 posToViewDirVec = normalize(cameraPos - vs_position);
	float specularConstant = pow(max(dot(posToViewDirVec, reflectDirVec), 0), 30);
	vec3 specularFinal = material.specular * specularConstant;

	fs_color = 
	texture(texture0, vs_texcoord) * vec4(vs_color, 1.0f)
	* (vec4(ambientLight, 1.f) + vec4(diffuseFinal, 1.f) + vec4(specularFinal, 1.f));
}