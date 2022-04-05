precision highp float;

uniform sampler2D u_origin;
varying vec2 texcoordOut;

uniform vec2 offset;
uniform float alpha;
uniform float eps;


vec3 meanBlur(vec3 colors[25]) {
    highp vec3 sum = vec3(0.0);
    for (int i = 0; i < 25; i++) {
        sum += colors[i];
    }
    return sum * 0.04;
}

void main()
{
    highp vec3 origin[25];
    
    origin[0] = texture2D(u_origin, texcoordOut).rgb;
    
    origin[1] = texture2D(u_origin, texcoordOut + vec2(offset.x, 0.0)).rgb;
    origin[2] = texture2D(u_origin, texcoordOut + vec2(-offset.x, 0.0)).rgb;
    origin[3] = texture2D(u_origin, texcoordOut + vec2(0.0, offset.y)).rgb;
    origin[4] = texture2D(u_origin, texcoordOut + vec2(0.0, -offset.y)).rgb;
    
    origin[5] = texture2D(u_origin, texcoordOut + vec2(offset.x, offset.y)).rgb;
    origin[6] = texture2D(u_origin, texcoordOut + vec2(offset.x, -offset.y)).rgb;
    origin[7] = texture2D(u_origin, texcoordOut + vec2(-offset.x, offset.y)).rgb;
    origin[8] = texture2D(u_origin, texcoordOut + vec2(-offset.x, -offset.y)).rgb;
    
    origin[9] = texture2D(u_origin, texcoordOut + vec2(2.0 * offset.x, 0)).rgb;
    origin[10] = texture2D(u_origin, texcoordOut + vec2(-2.0 * offset.x, 0)).rgb;
    origin[11] = texture2D(u_origin, texcoordOut + vec2(0, 2.0 * offset.y)).rgb;
    origin[12] = texture2D(u_origin, texcoordOut + vec2(0, -2.0 * offset.y)).rgb;
    
    origin[13] = texture2D(u_origin, texcoordOut + vec2(2.0 * offset.x, 2.0 * offset.y)).rgb;
    origin[14] = texture2D(u_origin, texcoordOut + vec2(2.0 * offset.x, -2.0 * offset.y)).rgb;
    origin[15] = texture2D(u_origin, texcoordOut + vec2(-2.0 * offset.x, 2.0 * offset.y)).rgb;
    origin[16] = texture2D(u_origin, texcoordOut + vec2(-2.0 * offset.x, -2.0 * offset.y)).rgb;
    
    origin[17] = texture2D(u_origin, texcoordOut + vec2(2.0 * offset.x, offset.y)).rgb;
    origin[18] = texture2D(u_origin, texcoordOut + vec2(-2.0 * offset.x, offset.y)).rgb;
    origin[19] = texture2D(u_origin, texcoordOut + vec2(offset.x, 2.0 * offset.y)).rgb;
    origin[20] = texture2D(u_origin, texcoordOut + vec2(-offset.x, 2.0 * offset.y)).rgb;
    
    origin[21] = texture2D(u_origin, texcoordOut + vec2(2.0 * offset.x, -offset.y)).rgb;
    origin[22] = texture2D(u_origin, texcoordOut + vec2(-2.0 * offset.x, -offset.y)).rgb;
    origin[23] = texture2D(u_origin, texcoordOut + vec2(offset.x, -2.0 * offset.y)).rgb;
    origin[24] = texture2D(u_origin, texcoordOut + vec2(-offset.x, -2.0 * offset.y)).rgb;
    
    highp vec3 origin2[25];
    for (int i = 0; i < 25; i++) {
        origin2[i] = origin[i] * origin[i];
    }
    
    
    highp vec3 originMean = meanBlur(origin);
    highp vec3 origin2Mean = meanBlur(origin2);
    
    highp vec3 originMean2 = originMean * originMean;
    
    
    highp vec3 variance = origin2Mean - originMean2;
    
    highp vec3 A = variance / (variance + eps);
    highp vec3 B = originMean - A * originMean;
    
    highp vec3 resultColor = A * origin[0] + B;
    resultColor = mix(origin[0], resultColor, alpha);
    
    gl_FragColor = vec4(resultColor, 1.0);
}
