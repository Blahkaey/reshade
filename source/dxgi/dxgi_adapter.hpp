/*
 * Copyright (C) 2014 Patrick Mours
 * SPDX-License-Identifier: BSD-3-Clause OR MIT
 */

#pragma once

#include <dxgi1_6.h>
#include <mutex>

struct D3D10Device;
struct D3D11Device;
struct D3D12CommandQueue;

struct DECLSPEC_UUID("f978e25f-2217-49e0-a893-cdafd6ee48b5") DXGIAdapter final : IDXGIAdapter4
{
	DXGIAdapter(IDXGIAdapter  *original);
	DXGIAdapter(IDXGIAdapter1 *original);
	~DXGIAdapter();

	DXGIAdapter(const DXGIAdapter &) = delete;
	DXGIAdapter &operator=(const DXGIAdapter &) = delete;

	#pragma region IUnknown
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	ULONG   STDMETHODCALLTYPE AddRef() override;
	ULONG   STDMETHODCALLTYPE Release() override;
	#pragma endregion
	#pragma region IDXGIObject
	HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID Name, UINT DataSize, const void *pData) override;
	HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID Name, const IUnknown *pUnknown) override;
	HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID Name, UINT *pDataSize, void *pData) override;
	HRESULT STDMETHODCALLTYPE GetParent(REFIID riid, void **ppParent) override;
	#pragma endregion
	#pragma region IDXGIAdapter
	HRESULT STDMETHODCALLTYPE EnumOutputs(UINT Output, IDXGIOutput **ppOutput) override;
	HRESULT STDMETHODCALLTYPE GetDesc(DXGI_ADAPTER_DESC *pDesc) override;
	HRESULT STDMETHODCALLTYPE CheckInterfaceSupport(REFGUID InterfaceName, LARGE_INTEGER *pUMDVersion) override;
	#pragma endregion
	#pragma region IDXGIAdapter1
	HRESULT STDMETHODCALLTYPE GetDesc1(DXGI_ADAPTER_DESC1 *pDesc) override;
	#pragma endregion
	#pragma region IDXGIAdapter2
	HRESULT STDMETHODCALLTYPE GetDesc2(DXGI_ADAPTER_DESC2 *pDesc) override;
	#pragma endregion
	#pragma region IDXGIAdapter3
	HRESULT STDMETHODCALLTYPE RegisterHardwareContentProtectionTeardownStatusEvent(HANDLE hEvent, DWORD *pdwCookie) override;
	void STDMETHODCALLTYPE UnregisterHardwareContentProtectionTeardownStatus(DWORD dwCookie) override;
	HRESULT STDMETHODCALLTYPE QueryVideoMemoryInfo(UINT NodeIndex, DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup, DXGI_QUERY_VIDEO_MEMORY_INFO *pVideoMemoryInfo) override;
	HRESULT STDMETHODCALLTYPE SetVideoMemoryReservation(UINT NodeIndex, DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup, UINT64 Reservation) override;
	HRESULT STDMETHODCALLTYPE RegisterVideoMemoryBudgetChangeNotificationEvent(HANDLE hEvent, DWORD *pdwCookie) override;
	void STDMETHODCALLTYPE UnregisterVideoMemoryBudgetChangeNotification(DWORD dwCookie) override;
	#pragma endregion
	#pragma region IDXGIAdapter4
	HRESULT STDMETHODCALLTYPE GetDesc3(DXGI_ADAPTER_DESC3 *pDesc) override;
	#pragma endregion

	bool check_and_upgrade_interface(REFIID riid);

	IDXGIAdapter *_orig;
	LONG _ref = 1;
	unsigned short _interface_version;
#if RESHADE_ADDON
#endif
};
