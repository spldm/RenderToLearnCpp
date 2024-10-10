//--------------------------------------------------------------------------------------
// DirectXTKSimpleSample.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Core.h"
#include "LessonsManager.h"

#include "FindMedia.h"

extern void ExitSample() noexcept;

using namespace DirectX;
using namespace DirectX::SimpleMath;

const int Core::FRAME_WIDTH = 1280;
const int Core::FRAME_HEIGHT = 720;

Core::Core() noexcept(false)
{
    // DirectX Tool Kit supports all feature levels
    m_deviceResources = std::make_unique<DX::DeviceResources>(
        DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_D24_UNORM_S8_UINT, 2,
        D3D_FEATURE_LEVEL_9_1);
    m_deviceResources->RegisterDeviceNotify(this);
}

// Initialize the Direct3D resources required to run.
void Core::initialize(HWND window, int width, int height)
{
    m_keyboard = std::make_unique<Keyboard>();

    m_mouse = std::make_unique<Mouse>();
    m_mouse->SetWindow(window);

    m_deviceResources->SetWindow(window, width, height);

    m_deviceResources->CreateDeviceResources();  	
    createDeviceDependentResources();

    m_deviceResources->CreateWindowSizeDependentResources();

    Matrix view = Matrix::CreateOrthographicOffCenter(0, 1280, 720, 0, 0, 1);
    m_batchEffect->SetProjection(view);

    // Set the viewport.
    auto context = m_deviceResources->GetD3DDeviceContext();
    auto viewport = m_deviceResources->GetScreenViewport();
    context->RSSetViewports(1, &viewport);
}

void Core::tick()
{
    update();
    render();
}

// Updates the world.
void Core::update()
{
    auto kb = m_keyboard->GetState();
    if (kb.Escape)
    {
        ExitSample();
    }
}

// Draws the scene.
void Core::render()
{
    // Don't try to render anything before the first Update.

    auto context = m_deviceResources->GetD3DDeviceContext();
    clear(0, 0, 0);

	LessonsManager::getInstance().render();

    // Draw coordinates
    m_sprites->Begin();
    wchar_t sMousePos[100];
    Mouse::State mouseState = m_mouse.get()->GetState();
    wsprintf(sMousePos, L"%d, %d", mouseState.x, mouseState.y);
    m_font->DrawString(m_sprites.get(), sMousePos, XMFLOAT2(FRAME_WIDTH - 110, 0), Colors::Yellow);
    m_sprites->End();

    // Show the new frame.
    m_deviceResources->Present();
}

void Core::clear(float r, float g, float b)
{
    // Clear the views
    auto context = m_deviceResources->GetD3DDeviceContext();
    auto renderTarget = m_deviceResources->GetRenderTargetView();

	float colorRGBA[4] = { r, g, b, 1.f };
    context->ClearRenderTargetView(renderTarget, colorRGBA);
    context->OMSetRenderTargets(1, &renderTarget, 0);
}

void Core::drawLine(XMFLOAT2 pt1, XMFLOAT2 pt2, XMFLOAT4 color) {
    auto context = m_deviceResources->GetD3DDeviceContext();
    context->OMSetBlendState(m_states->Opaque(), nullptr, 0xFFFFFFFF);
    context->OMSetDepthStencilState(m_states->DepthNone(), 0);
    context->RSSetState(m_states->CullCounterClockwise());

    m_batchEffect->Apply(context);

    context->IASetInputLayout(m_batchInputLayout.Get());

    m_batch->Begin();

    VertexPositionColor v1(XMFLOAT3(pt1.x, pt1.y, 0), color);
    VertexPositionColor v2(XMFLOAT3(pt2.x, pt2.y, 0), color);
    m_batch->DrawLine(v1, v2);

    m_batch->End();
}
#pragma endregion

#pragma region Message Handlers

#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Core::createDeviceDependentResources()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    auto device = m_deviceResources->GetD3DDevice();

    m_states = std::make_unique<CommonStates>(device);
    m_sprites = std::make_unique<SpriteBatch>(context);
    m_batch = std::make_unique<PrimitiveBatch<VertexPositionColor>>(context);

    m_batchEffect = std::make_unique<BasicEffect>(device);
    m_batchEffect->SetVertexColorEnabled(true);

    {
        void const* shaderByteCode;
        size_t byteCodeLength;

        m_batchEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);

        DX::ThrowIfFailed(
            device->CreateInputLayout(VertexPositionColor::InputElements,
                VertexPositionColor::InputElementCount,
                shaderByteCode, byteCodeLength,
                m_batchInputLayout.ReleaseAndGetAddressOf())
            );
    }

    wchar_t strFilePath[MAX_PATH];
    DX::FindMediaFile(strFilePath, MAX_PATH, L"SegoeUI_18.spritefont");
    m_font = std::make_unique<SpriteFont>(device, strFilePath);
}

void Core::OnDeviceLost()
{
    m_states.reset();
    m_sprites.reset();
    m_batch.reset();
    m_batchEffect.reset();
    m_font.reset();
    m_batchInputLayout.Reset();
}

void Core::OnDeviceRestored()
{
    createDeviceDependentResources();
}
#pragma endregion

