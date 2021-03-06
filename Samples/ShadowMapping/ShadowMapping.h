//
// Copyright (c) 2018 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../Common/AppBase.h"
#include "../Common/Model.h"

typedef struct PipelineDesc
{
    VezPipeline pipeline = VK_NULL_HANDLE;
    std::vector<VkShaderModule> shaderModules;
} PipelineDesc;

class ShadowMapping : public AppBase
{
public:
    ShadowMapping();

protected:
    void Initialize() final;
    void Cleanup() final;
    void Draw() final;
    void OnMouseMove(int x, int y) final;
    void OnMouseScroll(float x, float y) final;
    void OnResize(int width, int height) final;
    void Update(float timeElapsed) final;

private:
    void CreatePipelines();
    void CreateShadowMap();
    void CreateSampler();
    void CreateUniformBuffers();
    void CreateModel();    
    void CreateCommandBuffer();
    void DepthPass();
    void ScenePass();

    PipelineDesc m_depthPassPipeline;
    PipelineDesc m_scenePassPipeline;
    VkImage m_depthImage = VK_NULL_HANDLE;
    VkImageView m_depthImageView = VK_NULL_HANDLE;
    VezFramebuffer m_depthFramebuffer = VK_NULL_HANDLE;
    VkSampler m_sampler = VK_NULL_HANDLE;
    VkBuffer m_cameraMatrices = VK_NULL_HANDLE;
    VkBuffer m_lightMatrices = VK_NULL_HANDLE;
    Model m_model;
    VkQueue m_graphicsQueue = VK_NULL_HANDLE;
    VezCommandBuffer m_commandBuffer = VK_NULL_HANDLE;
    glm::vec3 m_cameraRotation = glm::vec3(0.0f);
    float m_cameraZoom = 1.0f;
};