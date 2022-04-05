precision highp float;

uniform sampler2D u_origin;
uniform sampler2D u_AB;
varying vec2 texcoordOut;

uniform vec2 offset;
uniform float alpha;

vec3 meanBlur(vec3 colors[25]) {
    highp vec3 sum = vec3(0.0);
    for (int i = 0; i < 25; i++) {
        sum += colors[i];
    }
    return sum * 0.04;
}

void main()
{
    highp vec3 colorA[25];
    highp vec2 texcoordA = vec2(texcoordOut.x * 0.5, texcoordOut.y);
    
    colorA[0] = texture2D(u_AB, texcoordA).rgb;
    
    colorA[1] = texture2D(u_AB, texcoordA + vec2(offset.x, 0.0)).rgb;
    colorA[2] = texture2D(u_AB, texcoordA + vec2(-offset.x, 0.0)).rgb;
    colorA[3] = texture2D(u_AB, texcoordA + vec2(0.0, offset.y)).rgb;
    colorA[4] = texture2D(u_AB, texcoordA + vec2(0.0, -offset.y)).rgb;
    
    colorA[5] = texture2D(u_AB, texcoordA + vec2(offset.x, offset.y)).rgb;
    colorA[6] = texture2D(u_AB, texcoordA + vec2(offset.x, -offset.y)).rgb;
    colorA[7] = texture2D(u_AB, texcoordA + vec2(-offset.x, offset.y)).rgb;
    colorA[8] = texture2D(u_AB, texcoordA + vec2(-offset.x, -offset.y)).rgb;
    
    colorA[9] = texture2D(u_AB, texcoordA + vec2(2.0 * offset.x, 0)).rgb;
    colorA[10] = texture2D(u_AB, texcoordA + vec2(-2.0 * offset.x, 0)).rgb;
    colorA[11] = texture2D(u_AB, texcoordA + vec2(0, 2.0 * offset.y)).rgb;
    colorA[12] = texture2D(u_AB, texcoordA + vec2(0, -2.0 * offset.y)).rgb;
    
    colorA[13] = texture2D(u_AB, texcoordA + vec2(2.0 * offset.x, 2.0 * offset.y)).rgb;
    colorA[14] = texture2D(u_AB, texcoordA + vec2(2.0 * offset.x, -2.0 * offset.y)).rgb;
    colorA[15] = texture2D(u_AB, texcoordA + vec2(-2.0 * offset.x, 2.0 * offset.y)).rgb;
    colorA[16] = texture2D(u_AB, texcoordA + vec2(-2.0 * offset.x, -2.0 * offset.y)).rgb;
    
    colorA[17] = texture2D(u_AB, texcoordA + vec2(2.0 * offset.x, offset.y)).rgb;
    colorA[18] = texture2D(u_AB, texcoordA + vec2(-2.0 * offset.x, offset.y)).rgb;
    colorA[19] = texture2D(u_AB, texcoordA + vec2(offset.x, 2.0 * offset.y)).rgb;
    colorA[20] = texture2D(u_AB, texcoordA + vec2(-offset.x, 2.0 * offset.y)).rgb;
    
    colorA[21] = texture2D(u_AB, texcoordA + vec2(2.0 * offset.x, -offset.y)).rgb;
    colorA[22] = texture2D(u_AB, texcoordA + vec2(-2.0 * offset.x, -offset.y)).rgb;
    colorA[23] = texture2D(u_AB, texcoordA + vec2(offset.x, -2.0 * offset.y)).rgb;
    colorA[24] = texture2D(u_AB, texcoordA + vec2(-offset.x, -2.0 * offset.y)).rgb;
    
    highp vec3 colorB[25];
    highp vec2 texcoordB = vec2(texcoordOut.x * 0.5 + 0.5, texcoordOut.y);
    
    colorB[0] = texture2D(u_AB, texcoordB).rgb;
    
    colorB[1] = texture2D(u_AB, texcoordB + vec2(offset.x, 0.0)).rgb;
    colorB[2] = texture2D(u_AB, texcoordB + vec2(-offset.x, 0.0)).rgb;
    colorB[3] = texture2D(u_AB, texcoordB + vec2(0.0, offset.y)).rgb;
    colorB[4] = texture2D(u_AB, texcoordB + vec2(0.0, -offset.y)).rgb;
    
    colorB[5] = texture2D(u_AB, texcoordB + vec2(offset.x, offset.y)).rgb;
    colorB[6] = texture2D(u_AB, texcoordB + vec2(offset.x, -offset.y)).rgb;
    colorB[7] = texture2D(u_AB, texcoordB + vec2(-offset.x, offset.y)).rgb;
    colorB[8] = texture2D(u_AB, texcoordB + vec2(-offset.x, -offset.y)).rgb;
    
    colorB[9] = texture2D(u_AB, texcoordB + vec2(2.0 * offset.x, 0)).rgb;
    colorB[10] = texture2D(u_AB, texcoordB + vec2(-2.0 * offset.x, 0)).rgb;
    colorB[11] = texture2D(u_AB, texcoordB + vec2(0, 2.0 * offset.y)).rgb;
    colorB[12] = texture2D(u_AB, texcoordB + vec2(0, -2.0 * offset.y)).rgb;
    
    colorB[13] = texture2D(u_AB, texcoordB + vec2(2.0 * offset.x, 2.0 * offset.y)).rgb;
    colorB[14] = texture2D(u_AB, texcoordB + vec2(2.0 * offset.x, -2.0 * offset.y)).rgb;
    colorB[15] = texture2D(u_AB, texcoordB + vec2(-2.0 * offset.x, 2.0 * offset.y)).rgb;
    colorB[16] = texture2D(u_AB, texcoordB + vec2(-2.0 * offset.x, -2.0 * offset.y)).rgb;
    
    colorB[17] = texture2D(u_AB, texcoordB + vec2(2.0 * offset.x, offset.y)).rgb;
    colorB[18] = texture2D(u_AB, texcoordB + vec2(-2.0 * offset.x, offset.y)).rgb;
    colorB[19] = texture2D(u_AB, texcoordB + vec2(offset.x, 2.0 * offset.y)).rgb;
    colorB[20] = texture2D(u_AB, texcoordB + vec2(-offset.x, 2.0 * offset.y)).rgb;
    
    colorB[21] = texture2D(u_AB, texcoordB + vec2(2.0 * offset.x, -offset.y)).rgb;
    colorB[22] = texture2D(u_AB, texcoordB + vec2(-2.0 * offset.x, -offset.y)).rgb;
    colorB[23] = texture2D(u_AB, texcoordB + vec2(offset.x, -2.0 * offset.y)).rgb;
    colorB[24] = texture2D(u_AB, texcoordB + vec2(-offset.x, -2.0 * offset.y)).rgb;
    
    highp vec3 meanA = meanBlur(colorA);
    highp vec3 meanB = meanBlur(colorB);
    
    meanA = meanA * 2.0 - 1.0;
    meanB = meanB * 2.0 - 1.0;
    
    highp vec3 originColor = texture2D(u_origin, texcoordOut).rgb;
    highp vec3 resultColor = meanA * originColor + meanB;
    resultColor = mix(originColor, resultColor, alpha);
    
    gl_FragColor = vec4(resultColor, 1.0);
}
