// Clean-Room LayerFlow Dense Hair Bridge
namespace convert2 {
namespace layerflow {

class DenseHairBridge {
public:
    void setAlpha(float alpha) { m_alpha = alpha; }
    void setHighlights(float hl) { m_highlights = hl; }
    void setMaterialId(int id) { m_materialId = id; }
private:
    float m_alpha = 1.0f;
    float m_highlights = 0.5f;
    int m_materialId = 2305;
};

} // namespace layerflow
} // namespace convert2
