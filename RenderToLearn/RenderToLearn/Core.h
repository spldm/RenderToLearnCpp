//--------------------------------------------------------------------------------------
// Core.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once
  	
#include "DeviceResources.h"

using namespace DirectX;

// A basic sample implementation that creates a D3D11 device and
// provides a render loop.
class Core final : public DX::IDeviceNotify
{
public:
    static const int FRAME_WIDTH;
    static const int FRAME_HEIGHT;

	static Core& getInstance() {
		static Core instance;
		return instance;
    }

    // Initialization and management
    void initialize(HWND window, int width, int height);

    // Basic render loop
    void tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    void clear(float r, float g, float b);
    void drawLine(XMFLOAT2 pos1, XMFLOAT2 pos2, XMFLOAT4 color);
private:
    Core() noexcept(false);
    ~Core() = default;

    Core(Core&&) = delete;
    Core& operator= (Core&&) = delete;

    Core(Core const&) = delete;
    Core& operator= (Core const&) = delete;

    void update();
    void render();

    void createDeviceDependentResources();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_deviceResources;

    // Input devices.
    std::unique_ptr<DirectX::Keyboard>      m_keyboard;
    std::unique_ptr<DirectX::Mouse>         m_mouse;

    // DirectXTK objects.
    std::unique_ptr<DirectX::CommonStates>                                  m_states;
    std::unique_ptr<DirectX::BasicEffect>                                   m_batchEffect;
    std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>  m_batch;
    std::unique_ptr<DirectX::SpriteBatch>                                   m_sprites;
    std::unique_ptr<DirectX::SpriteFont>                                    m_font;

    Microsoft::WRL::ComPtr<ID3D11InputLayout>                               m_batchInputLayout;

    DirectX::SimpleMath::Matrix                                             m_world;
    DirectX::SimpleMath::Matrix                                             m_view;
    DirectX::SimpleMath::Matrix                                             m_projection;
};
