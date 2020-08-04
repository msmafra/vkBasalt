#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt
{
    struct VkBasaltImage
    {
        VkImage        image  = VK_NULL_HANDLE;
        VkDeviceMemory memory = VK_NULL_HANDLE;
    };

    struct VkBasaltImageInfo
    {
        VkExtent3D        extent;
        VkFormat          format;
        VkImageUsageFlags usage;
        uint32_t          mipLevels = 1;
    };

    void createImage2(LogicalDevice* pLogicalDevice, VkBasaltImageInfo* pCreateInfo, VkBasaltImage* pImage);
    void createImages2(LogicalDevice* pLogicalDevice, VkBasaltImageInfo* pCreateInfo, uint32_t count, VkBasaltImage* pImages);

    std::vector<VkImage> createImages(LogicalDevice*        pLogicalDevice,
                                      uint32_t              count,
                                      VkExtent3D            extent,
                                      VkFormat              format,
                                      VkImageUsageFlags     usage,
                                      VkMemoryPropertyFlags properties,
                                      VkDeviceMemory&       imageMemory,
                                      uint32_t              mipLevels = 1);

    void uploadToImage(
        LogicalDevice* pLogicalDevice, VkImage image, VkExtent3D extent, uint32_t size, const unsigned char* writeData, uint32_t mipLevels = 1);

    void changeImageLayout(LogicalDevice* pLogicalDevice, std::vector<VkImage> images, uint32_t mipLevels = 1);

    void generateMipMaps(LogicalDevice* pLogicalDevice, VkCommandBuffer commandBuffer, VkImage image, VkExtent3D extent, uint32_t mipLevels);
} // namespace vkBasalt

#endif // IMAGE_HPP_INCLUDED
